	push {r4, lr}
	bl m4aSoundVSync
	ldr r1, _08229FEC @ =0x03002CE4
	movs r0, #1
	str r0, [r1]
	ldr r0, _08229FF0 @ =0x0300350C
	ldr r0, [r0]
	cmp r0, #0
	bne _08229FA2
	b _0822A0FC
_08229FA2:
	ldr r1, _08229FF4 @ =0x03003508
	ldr r0, _08229FF8 @ =0x03002CE8
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _08229FFC @ =0x03002CEC
	ldr r0, _0822A000 @ =0x03003520
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0822A004 @ =0x04000010
	ldr r2, _0822A008 @ =0x03003EC0
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #2]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #4]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #6]
	strh r0, [r1]
	ldr r0, _0822A00C @ =0x03003E8C
	ldrh r0, [r0]
	cmp r0, #0
	bne _0822A010
	adds r1, #2
	ldrh r0, [r2, #8]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0xa]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0xc]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0xe]
	b _0822A048
	.align 2, 0
_08229FEC: .4byte 0x03002CE4
_08229FF0: .4byte 0x0300350C
_08229FF4: .4byte 0x03003508
_08229FF8: .4byte 0x03002CE8
_08229FFC: .4byte 0x03002CEC
_0822A000: .4byte 0x03003520
_0822A004: .4byte 0x04000010
_0822A008: .4byte 0x03003EC0
_0822A00C: .4byte 0x03003E8C
_0822A010:
	ldr r2, _0822A078 @ =0x04000020
	ldr r1, _0822A07C @ =0x03003E90
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #2]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #4]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #6]
	strh r0, [r2]
	ldr r1, _0822A080 @ =0x04000028
	ldr r3, _0822A084 @ =0x03003EB8
	ldr r0, [r3]
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0822A088 @ =0x0FFF0000
	ands r0, r2
	lsrs r0, r0, #0x10
	strh r0, [r1]
	adds r1, #2
	ldr r0, [r3, #4]
	strh r0, [r1]
	adds r1, #2
	ands r0, r2
	lsrs r0, r0, #0x10
_0822A048:
	strh r0, [r1]
	ldr r0, _0822A08C @ =0x03003514
	movs r1, #0
	ldrsh r3, [r0, r1]
	cmp r3, #0
	beq _0822A0B4
	ldr r2, _0822A090 @ =0x040000B8
	movs r0, #0
	str r0, [r2]
	ldr r1, _0822A094 @ =0x040000B0
	ldr r0, _0822A098 @ =0x03003518
	ldr r0, [r0]
	str r0, [r1]
	adds r1, #4
	ldr r0, _0822A09C @ =0x03002CA0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0822A0A0 @ =0x03003510
	ldrh r1, [r0]
	cmp r3, #1
	beq _0822A0A8
	ldr r0, _0822A0A4 @ =0xA6600000
	b _0822A0AA
	.align 2, 0
_0822A078: .4byte 0x04000020
_0822A07C: .4byte 0x03003E90
_0822A080: .4byte 0x04000028
_0822A084: .4byte 0x03003EB8
_0822A088: .4byte 0x0FFF0000
_0822A08C: .4byte 0x03003514
_0822A090: .4byte 0x040000B8
_0822A094: .4byte 0x040000B0
_0822A098: .4byte 0x03003518
_0822A09C: .4byte 0x03002CA0
_0822A0A0: .4byte 0x03003510
_0822A0A4: .4byte 0xA6600000
_0822A0A8:
	ldr r0, _0822A0B0 @ =0xA2600000
_0822A0AA:
	orrs r0, r1
	str r0, [r2]
	b _0822A0BE
	.align 2, 0
_0822A0B0: .4byte 0xA2600000
_0822A0B4:
	ldr r0, _0822A0D4 @ =0x040000B0
	str r3, [r0]
	str r3, [r0, #4]
	str r3, [r0, #8]
	ldr r0, [r0, #8]
_0822A0BE:
	ldr r0, _0822A0D8 @ =0x03003500
	movs r1, #1
	str r1, [r0]
	bl FUN_0804ba48
	cmp r0, #0
	beq _0822A0DC
	bl rfu_LMAN_syncVBlank
	b _0822A0F0
	.align 2, 0
_0822A0D4: .4byte 0x040000B0
_0822A0D8: .4byte 0x03003500
_0822A0DC:
	bl FUN_0804b260
	cmp r0, #0
	beq _0822A0F0
	ldr r4, _0822A108 @ =0x03002B54
	bl rfu_syncVBlank
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4]
_0822A0F0:
	bl FUN_0823dc70
	ldr r1, _0822A10C @ =0x03003504
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0822A0FC:
	ldr r1, _0822A110 @ =0x03007FF8
	movs r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822A108: .4byte 0x03002B54
_0822A10C: .4byte 0x03003504
_0822A110: .4byte 0x03007FF8
