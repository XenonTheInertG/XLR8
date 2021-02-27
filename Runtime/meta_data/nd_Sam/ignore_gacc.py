
  
import discord;
from discord.ext import commands;

bot = commands.Bot(command_prefix='$');

@bot.event
async def on_ready():
    print('PING STARTED');


@bot.event
async def on_message(message):

    if message.content.startswith('$Ping'):
        channel = message.channel;
        while 1==1:
            await channel.send('@everyone');



bot.run(''); #Insert your bot token here

