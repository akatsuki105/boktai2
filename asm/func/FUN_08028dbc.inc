	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #4
	adds r0, r0, r7
	mov r8, r0
	ldr r0, _08028E28 @ =0x0000CB05
	ldr r1, _08028E2C @ =0x0000DE23
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r0, r7, r2
	adds r3, r0, #0
	adds r2, r1, #0
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldm r2!, {r4, r5}
	stm r3!, {r4, r5}
	bl OpenMainSpriteFile
	movs r6, #0xc5
	lsls r6, r6, #2
	adds r0, r7, r6
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r6, r7, r0
	add r5, sp, #0x10
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08028E30
	asrs r0, r0, #8
	b _08028E36
	.align 2, 0
_08028E28: .4byte 0x0000CB05
_08028E2C: .4byte 0x0000DE23
_08028E30:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08028E36:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08028E48
	asrs r0, r0, #8
	b _08028E4E
_08028E48:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08028E4E:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r5, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08028E62
	asrs r0, r0, #8
	b _08028E68
_08028E62:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08028E68:
	subs r2, r4, r0
	movs r5, #0
	adds r4, r4, r0
	ldr r3, _08028EB4 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r4, #0xa2
	lsls r4, r4, #4
	adds r1, r7, r4
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	mov r0, r8
	movs r2, #0
	movs r3, #0x11
	bl MainSprite_Add
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028EB4: .4byte 0x030047C8
