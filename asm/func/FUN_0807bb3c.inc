	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	bne _0807BB54
	ldr r0, _0807BB50 @ =0x0000049C
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	b _0807BB5C
	.align 2, 0
_0807BB50: .4byte 0x0000049C
_0807BB54:
	ldr r0, _0807BBA0 @ =0x0000049C
	adds r2, r4, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
_0807BB5C:
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [sp, #0xc]
	str r0, [r1]
	ldr r1, _0807BBA4 @ =0x000004A6
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #3
	adds r0, r4, r1
	strb r5, [r0]
	ldr r0, _0807BBA8 @ =0x000004A7
	adds r1, r4, r0
	movs r0, #0x96
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BBAC @ =FUN_08072d48
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BBA0: .4byte 0x0000049C
_0807BBA4: .4byte 0x000004A6
_0807BBA8: .4byte 0x000004A7
_0807BBAC: .4byte FUN_08072d48
