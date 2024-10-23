#include "TestingDB.h"

#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

// TODO: Client Options, what can be done with it? What should I expose the user to in blueprint?

// TODO: I also need to expose the database and collection to the user in blueprints ( the name of the database we are going to load, and the name of the collection we are going to load)

void UTestingDB::Test()
{
	using namespace mongocxx;
	
	try
	{
		mongocxx::uri uri(TCHAR_TO_UTF8(*UriString));
		
		mongocxx::options::client client_options;
		const auto api = mongocxx::options::server_api
		{
			mongocxx::options::server_api::version::k_version_1
		};

		client_options.server_api_opts(api);

		mongocxx::client conn { uri, client_options };
		mongocxx::database db = conn[TCHAR_TO_UTF8(*DatabaseName)];

		const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
		const auto result = db.run_command(ping_cmd.view());
		FString Value = UTF8_TO_TCHAR(result.view);
				
		UE_LOG(LogTemp, Warning, TEXT("Pinged deployment. Success!"));
		
	}
	catch (const std::exception& Exception)
	{
		FString ExceptionMessage = UTF8_TO_TCHAR(Exception.what());
		UE_LOG(LogTemp, Error, TEXT("Exception: %s"), *ExceptionMessage);		
	}

	// TArray<
}
