	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEA0E
	adds r0, r4, #0
	bl FUN_081dd9f0
	ldr r0, _081DEA24 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DEA0E
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DEA0E
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #6
	bl FUN_081ddfb0
	ldr r3, _081DEA28 @ =0x000002CA
	adds r1, r4, r3
	strh r0, [r1]
_081DEA0E:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DEA2C
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEAD2
	.align 2, 0
_081DEA24: .4byte 0x03002C68
_081DEA28: .4byte 0x000002CA
_081DEA2C:
	ldr r0, _081DEAD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DEA4A
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DEA4A
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r4, #0
	movs r2, #8
	bl FUN_081ddb14
_081DEA4A:
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r5, r4, r3
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #8
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DEAD2
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081ddfb0
	ldr r2, _081DEADC @ =FUN_081deaf4
	adds r0, r4, #0
	movs r1, #0xa
	bl Entity9A9F_SetState
	bl FUN_08049fa8
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081ddf84
	ldr r2, _081DEAE0 @ =0x030046B8
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldr r5, _081DEAE4 @ =0x000003FF
	adds r1, r5, #0
	ands r1, r0
	str r1, [r2]
	ldr r3, _081DEAE8 @ =0x000002CE
	adds r0, r4, r3
	ldrb r0, [r0]
	strh r0, [r4, #0x38]
	cmp r0, #2
	bls _081DEABC
	adds r0, r1, #1
	ands r0, r5
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081DEAEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	strh r0, [r4, #0x38]
_081DEABC:
	adds r0, r4, #0
	bl FUN_081ddf44
	ldr r1, _081DEAF0 @ =0x03004510
	adds r2, r5, #0
	adds r0, r1, #6
_081DEAC8:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _081DEAC8
	movs r0, #0
_081DEAD2:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DEAD8: .4byte 0x03002C68
_081DEADC: .4byte FUN_081deaf4
_081DEAE0: .4byte 0x030046B8
_081DEAE4: .4byte 0x000003FF
_081DEAE8: .4byte 0x000002CE
_081DEAEC: .4byte 0x0203B400
_081DEAF0: .4byte 0x03004510
