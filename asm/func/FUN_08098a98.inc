	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	mov r8, r3
	adds r4, r4, r5
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	subs r6, r4, r0
	movs r4, #0xa
	cmp r5, #0
	bgt _08098AC8
	movs r4, #0
	cmp r5, #0
	bge _08098AC8
	movs r4, #0x14
_08098AC8:
	adds r2, r4, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, r8
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetPose
	adds r2, r4, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x18]
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetPose
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
