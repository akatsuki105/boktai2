	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _081E63AC @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6410
	movs r2, #1
	ldr r0, _081E63B0 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E63B4
	movs r0, #1
	b _081E63B6
	.align 2, 0
_081E63AC: .4byte 0x00001614
_081E63B0: .4byte 0x00001610
_081E63B4:
	movs r0, #0
_081E63B6:
	cmp r0, #0
	beq _081E63CC
	bl Marquee_Clear
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081E63CC:
	ldr r1, _081E63FC @ =0x0000160C
	adds r4, r5, r1
	ldr r0, [r4]
	ldr r2, _081E6400 @ =0x000015F4
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #7
	bl TextPanel_SetMessage
	ldr r0, _081E6404 @ =0x000002AE
	bl PlaySound_082406e0
	ldr r0, _081E6408 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E640C @ =0x00001614
	adds r0, r5, r1
	strb r2, [r0]
	b _081E6448
	.align 2, 0
_081E63FC: .4byte 0x0000160C
_081E6400: .4byte 0x000015F4
_081E6404: .4byte 0x000002AE
_081E6408: .4byte 0x0000162A
_081E640C: .4byte 0x00001614
_081E6410:
	ldr r2, _081E6434 @ =0x0000162A
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	bne _081E6448
	movs r0, #0xc8
	lsls r0, r0, #1
	movs r1, #0
	bl LinkConnect_Create
	cmp r0, #0
	bne _081E6438
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_081e4c40
	b _081E6448
	.align 2, 0
_081E6434: .4byte 0x0000162A
_081E6438:
	ldr r1, _081E6450 @ =FUN_081e4bdc
	ldr r2, _081E6454 @ =FUN_081e4c40
	adds r0, r5, #0
	bl LinkConnect_SetCallbacks
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081E6448:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6450: .4byte FUN_081e4bdc
_081E6454: .4byte FUN_081e4c40
