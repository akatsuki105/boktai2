	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _080A3494 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080A34C4
	mov r8, r2
_080A346A:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r4, #6]
	cmp r0, #7
	beq _080A3498
	cmp r0, #8
	beq _080A34A8
	b _080A34B0
	.align 2, 0
_080A3494: .4byte 0x03002B4C
_080A3498:
	adds r0, r7, #0
	ldr r1, _080A34A4 @ =FUN_080a2a4c
	bl FUN_080a2a14
	b _080A34B0
	.align 2, 0
_080A34A4: .4byte FUN_080a2a4c
_080A34A8:
	adds r0, r7, #0
	ldr r1, _080A34D0 @ =FUN_080a2b78
	bl FUN_080a2a14
_080A34B0:
	adds r5, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _080A346A
_080A34C4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A34D0: .4byte FUN_080a2b78
