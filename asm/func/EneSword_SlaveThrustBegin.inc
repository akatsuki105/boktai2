	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r2, [r0, #0x18]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0x1c
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x20
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	movs r1, #0x89
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sl, r1
	strb r0, [r1]
	movs r1, #0xa0
	subs r1, r1, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	ldr r2, _08198FA0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08198FA4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08198FA8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #1
	ands r0, r2
	movs r3, #1
	rsbs r3, r3, #0
	adds r1, r3, #0
	cmp r0, #0
	beq _08198EB8
	movs r1, #1
_08198EB8:
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _08198FAC @ =0x00000183
	adds r0, r7, r1
	strb r2, [r0]
	ldrh r0, [r7, #0x1c]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	strh r0, [r2]
	ldrh r0, [r7, #0x1e]
	subs r3, #0x4c
	adds r6, r7, r3
	strh r0, [r6]
	ldrh r0, [r7, #0x20]
	subs r1, #0x4b
	adds r1, r7, r1
	str r1, [sp, #4]
	strh r0, [r1]
	mov r2, sl
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _08198FB0 @ =gSineTable
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r4, #0x80
	lsls r4, r4, #5
	adds r1, r4, #0
	bl Div
	ldrh r1, [r7, #0x1c]
	adds r1, r1, r0
	movs r3, #0x96
	lsls r3, r3, #1
	adds r5, r7, r3
	strh r1, [r5]
	ldr r1, [sp]
	ldr r0, [r1, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	movs r2, #0x97
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	strh r0, [r2]
	mov r3, sl
	ldrb r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08198FB0 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r4, #0
	bl Div
	ldrh r1, [r7, #0x20]
	adds r1, r1, r0
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r0, [r5]
	mov r3, r8
	ldrh r1, [r3]
	subs r0, r0, r1
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	mov r1, sb
	ldrh r0, [r1]
	ldrh r1, [r6]
	subs r0, r0, r1
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r0, [r3]
	ldrh r0, [r2]
	ldr r2, [sp, #4]
	ldrh r1, [r2]
	subs r0, r0, r1
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _08198FB4 @ =EneSword_SlaveThrustAim
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08198FA0: .4byte 0x030046B8
_08198FA4: .4byte 0x000003FF
_08198FA8: .4byte 0x0203B400
_08198FAC: .4byte 0x00000183
_08198FB0: .4byte gSineTable
_08198FB4: .4byte EneSword_SlaveThrustAim
