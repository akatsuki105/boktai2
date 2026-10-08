	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _080B23A4 @ =0x000017A8
	adds r5, r7, r0
	movs r6, #0
	ldr r2, _080B23A8 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	ldr r3, _080B23AC @ =0x000017AE
	adds r0, r7, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _080B23EC
	mov r8, r2
_080B2378:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _080B23B0
	cmp r0, #1
	beq _080B23C8
	b _080B23D8
	.align 2, 0
_080B23A4: .4byte 0x000017A8
_080B23A8: .4byte 0x03002B4C
_080B23AC: .4byte 0x000017AE
_080B23B0:
	ldrh r1, [r4, #8]
	ldr r2, _080B23C4 @ =0x00000C11
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl MsgQueue_EndWait
	b _080B23D8
	.align 2, 0
_080B23C4: .4byte 0x00000C11
_080B23C8:
	adds r0, r7, #0
	ldr r1, _080B23F8 @ =FUN_080ada44
	bl EntityCBB0_SetState
	adds r0, r5, #0
	movs r1, #1
	bl MsgQueue_EndWait
_080B23D8:
	adds r6, #1
	mov r3, r8
	ldr r1, [r3]
	adds r1, #0x24
	adds r0, r5, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	blt _080B2378
_080B23EC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B23F8: .4byte FUN_080ada44
