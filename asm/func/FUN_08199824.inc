	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #6]
	adds r0, #0x14
	strb r0, [r7, #6]
	adds r4, r7, #0
	adds r4, #0xf8
	ldrh r0, [r4]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	adds r5, r7, #0
	adds r5, #0xfc
	ldrh r0, [r5]
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
	movs r3, #0x8f
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #5
	bl Mod
	cmp r0, #0
	beq _0819986C
	b _081999E2
_0819986C:
	movs r6, #0
	ldrsh r0, [r4, r6]
	cmp r0, #0
	beq _08199876
	b _081999A8
_08199876:
	movs r0, #0
	ldrsh r2, [r5, r0]
	cmp r2, #0
	beq _08199880
	b _081999A8
_08199880:
	adds r1, r7, #0
	adds r1, #0xa2
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r4, r7, r2
	ldr r0, [r4]
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r0]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r5, #0x9a
	lsls r5, r5, #1
	adds r3, r7, r5
	ldrh r0, [r3]
	subs r1, r1, r0
	movs r6, #0xa6
	lsls r6, r6, #1
	adds r6, r6, r7
	mov r8, r6
	strh r1, [r6]
	ldr r0, [r4]
	movs r1, #0xa3
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r0, #2]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r2, r2, r7
	mov ip, r2
	ldrh r0, [r2]
	subs r1, r1, r0
	adds r5, #0x1a
	adds r5, r5, r7
	mov sl, r5
	strh r1, [r5]
	ldr r0, [r4]
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r0, #4]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp]
	strh r1, [r5]
	mov r6, r8
	ldrh r0, [r6]
	ldrh r1, [r3]
	adds r0, r0, r1
	movs r5, #0x96
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	mov r6, sl
	ldrh r0, [r6]
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r6, #0x97
	lsls r6, r6, #1
	adds r6, r6, r7
	mov sb, r6
	strh r0, [r6]
	ldr r5, [sp]
	ldrh r0, [r5]
	ldrh r6, [r2]
	adds r0, r0, r6
	movs r5, #0x98
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #4]
	strh r0, [r5]
	ldrh r0, [r7, #0x1c]
	strh r0, [r3]
	ldrh r0, [r7, #0x1e]
	mov r6, ip
	strh r0, [r6]
	ldrh r0, [r7, #0x20]
	strh r0, [r2]
	ldrh r0, [r1]
	ldrh r1, [r3]
	subs r0, r0, r1
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	mov r5, sb
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r0, r1
	movs r6, #0x9f
	lsls r6, r6, #1
	adds r3, r7, r6
	strh r0, [r3]
	ldr r1, [sp, #4]
	ldrh r0, [r1]
	ldrh r1, [r2]
	subs r0, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	ldr r0, [r4]
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3]
	ldr r0, [r4]
	ldrh r0, [r0, #2]
	mov r5, sl
	strh r0, [r5]
	ldr r0, [r4]
	ldrh r0, [r0, #4]
	ldr r6, [sp]
	strh r0, [r6]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r2, #0x45
	adds r1, r7, r2
	movs r0, #0xf1
	strb r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, _081999BC @ =FUN_081996f0
	str r0, [r1]
_081999A8:
	adds r0, r7, #0
	adds r0, #0xf8
	movs r5, #0
	ldrsh r1, [r0, r5]
	adds r2, r0, #0
	cmp r1, #0
	blt _081999C0
	asrs r0, r1, #1
	b _081999C6
	.align 2, 0
_081999BC: .4byte FUN_081996f0
_081999C0:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081999C6:
	strh r0, [r2]
	adds r0, r7, #0
	adds r0, #0xfc
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r2, r0, #0
	cmp r1, #0
	blt _081999DA
	asrs r0, r1, #1
	b _081999E0
_081999DA:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081999E0:
	strh r0, [r2]
_081999E2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
