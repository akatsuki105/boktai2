	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x48
	ldr r1, _080A8DC4 @ =0x0000E74B
	adds r0, r6, #0
	bl Video_GetActorSprite
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #0xc
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x68]
	str r0, [r5, #0x38]
	str r1, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x38
	movs r1, #0x80
	bl FUN_082342cc
	cmp r0, #0
	beq _080A8DC8
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r6, #0
	bl Video_SetActorSpritePltt
	adds r1, r5, #0
	adds r1, #0x23
	movs r0, #1
	b _080A8DCE
	.align 2, 0
_080A8DC4: .4byte 0x0000E74B
_080A8DC8:
	adds r1, r5, #0
	adds r1, #0x23
	movs r0, #2
_080A8DCE:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
