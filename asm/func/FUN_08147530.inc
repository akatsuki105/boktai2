	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08147548 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814754C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814754E
	.align 2, 0
_08147548: .4byte 0x0000046D
_0814754C:
	movs r0, #0
_0814754E:
	cmp r0, #0
	beq _08147570
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080efb60
	movs r1, #0x97
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08147570:
	cmp r5, #0xa0
	bne _0814758C
	ldr r1, _08147588 @ =0x000001DF
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	b _081475A8
	.align 2, 0
_08147588: .4byte 0x000001DF
_0814758C:
	cmp r5, #0xa0
	ble _081475A8
	ldr r1, _081475B0 @ =0x00000454
	adds r0, r4, r1
	ldr r0, [r0]
	bl Emote_IsInactive
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081475A8
	ldr r0, _081475B4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081475A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081475B0: .4byte 0x00000454
_081475B4: .4byte 0x0000046B
