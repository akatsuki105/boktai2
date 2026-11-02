	push {r4, r5, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053E8E
	movs r1, #0
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x20]
	cmp r0, #3
	beq _08053E8E
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #3
	movs r3, #1
	bl BlackPantherElem_PlayAnim
_08053E8E:
	ldr r0, [r4, #0x1c]
	cmp r0, #0xf
	bhi _08053ECA
	ldr r2, _08053EB0 @ =gSineTable
	lsls r0, r0, #3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xa4
	muls r0, r1, r0
	cmp r0, #0
	blt _08053EB4
	asrs r0, r0, #0xc
	b _08053EBA
	.align 2, 0
_08053EB0: .4byte gSineTable
_08053EB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08053EBA:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	adds r0, r4, #0
	adds r0, #0x76
	strh r1, [r0]
	adds r3, r0, #0
	b _08053ED8
_08053ECA:
	adds r1, r4, #0
	adds r1, #0x76
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r2, _08053EF4 @ =gSineTable
	adds r3, r1, #0
_08053ED8:
	ldr r0, [r4, #0x1c]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08053EF8
	asrs r0, r0, #0xc
	b _08053EFE
	.align 2, 0
_08053EF4: .4byte gSineTable
_08053EF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08053EFE:
	ldr r1, _08053F34 @ =0x00000DAC
	adds r5, r1, #0
	subs r0, r5, r0
	adds r2, r4, #0
	adds r2, #0x78
	strh r0, [r2]
	ldr r0, [r4, #0x1c]
	subs r0, #0xe
	cmp r0, #5
	bhi _08053F1A
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
_08053F1A:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x1f
	bls _08053F38
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3]
	strh r5, [r2]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0
	b _08053F3A
	.align 2, 0
_08053F34: .4byte 0x00000DAC
_08053F38:
	adds r0, #1
_08053F3A:
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
