	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, _0819B380 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819B384
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819B386
	.align 2, 0
_0819B380: .4byte 0x0000046D
_0819B384:
	movs r0, #0
_0819B386:
	cmp r0, #0
	beq _0819B3CC
	adds r0, r5, #0
	bl FUN_0819f990
	ldr r0, _0819B41C @ =0x00000C98
	adds r1, r6, r0
	adds r0, r5, #0
	bl FUN_0819fcf0
	ldr r0, _0819B420 @ =0x0000093E
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0819B424 @ =0x00000CBC
	adds r0, r6, r1
	bl ParticleShadow_Show
	ldr r0, _0819B428 @ =0x000008BC
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xf7
	bl FUN_0819fd0c
	ldr r0, _0819B42C @ =0x0000016F
	bl PlaySound_082406e0
_0819B3CC:
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_0819f934
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819B444
	ldr r4, _0819B430 @ =FUN_0819b478
	movs r3, #0x2b
	ldr r0, _0819B434 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819B438 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, _0819B43C @ =0x0000093C
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xfa
	bl FUN_0819fd0c
	ldr r0, _0819B440 @ =0x0000016D
	bl PlaySound_082406e0
	b _0819B46C
	.align 2, 0
_0819B41C: .4byte 0x00000C98
_0819B420: .4byte 0x0000093E
_0819B424: .4byte 0x00000CBC
_0819B428: .4byte 0x000008BC
_0819B42C: .4byte 0x0000016F
_0819B430: .4byte FUN_0819b478
_0819B434: .4byte 0x0000046D
_0819B438: .4byte 0x0000046B
_0819B43C: .4byte 0x0000093C
_0819B440: .4byte 0x0000016D
_0819B444:
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0819B460
	ldr r0, _0819B45C @ =0x000008BC
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xf7
	bl FUN_0819fd0c
	b _0819B46C
	.align 2, 0
_0819B45C: .4byte 0x000008BC
_0819B460:
	ldr r0, _0819B474 @ =0x0000093C
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xfa
	bl FUN_0819fd0c
_0819B46C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819B474: .4byte 0x0000093C
