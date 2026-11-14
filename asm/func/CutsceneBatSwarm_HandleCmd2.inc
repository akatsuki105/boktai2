	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r2, #0
	ldrh r1, [r4, #8]
	ldr r2, _08011F54 @ =0x00000CA6
	adds r0, r5, r2
	strh r1, [r0]
	ldrh r0, [r0]
	bl Mover_FindByID_Proxy
	cmp r0, #0
	bne _08011F58
	movs r0, #1
	rsbs r0, r0, #0
	b _08011FEE
	.align 2, 0
_08011F54: .4byte 0x00000CA6
_08011F58:
	ldr r1, [r0, #8]
	ldr r2, [r0, #0xc]
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r3, #0xa
	ldrsh r2, [r4, r3]
	str r2, [sp]
	movs r0, #0
	str r0, [r5, #0x1c]
	ldr r0, _08012000 @ =0x0203B400
	mov sl, r0
	ldr r1, _08012004 @ =0x030046B8
	mov sb, r1
	ldr r2, _08012008 @ =0x000003FF
	mov r8, r2
	movs r6, #0xf
	adds r4, r5, #0
	adds r4, #0x24
_08011F7C:
	movs r0, #3
	strb r0, [r4, #1]
	movs r7, #1
	strb r7, [r4]
	movs r3, #0
	strh r3, [r4, #4]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x1c
	ldrsh r1, [r4, r3]
	movs r3, #0x14
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
	mov r1, sb
	ldr r2, [r1]
	adds r2, #1
	mov r3, r8
	ands r2, r3
	lsls r1, r2, #1
	add r1, sl
	ldrh r3, [r1]
	subs r0, #0x10
	movs r1, #0x1f
	ands r3, r1
	adds r0, r0, r3
	strb r0, [r4, #6]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, #0xc]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	mov r3, sb
	str r2, [r3]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r4, #8]
	subs r6, #1
	adds r4, #0xc8
	cmp r6, #0
	bge _08011F7C
	str r7, [r5, #0x18]
	movs r0, #0
_08011FEE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08012000: .4byte 0x0203B400
_08012004: .4byte 0x030046B8
_08012008: .4byte 0x000003FF
