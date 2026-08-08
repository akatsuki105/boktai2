	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	adds r4, r1, #0
	mov r8, r6
	ldrh r0, [r4]
	strh r0, [r6, #0x10]
	ldrh r0, [r4, #4]
	strh r0, [r6, #0x14]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	mov sb, r0
	ldr r1, _080E4FC8 @ =0x00000256
	adds r0, r6, r1
	ldrh r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E4FCC
	adds r0, #4
	b _080E4FD8
	.align 2, 0
_080E4FC8: .4byte 0x00000256
_080E4FCC:
	ldr r0, _080E4FEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E4FD8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E4FF0
	cmp r2, #2
	beq _080E4FF4
	b _080E4FF8
	.align 2, 0
_080E4FEC: .4byte 0x030046A4
_080E4FF0:
	ldrb r0, [r7, #4]
	b _080E4FF6
_080E4FF4:
	ldrb r0, [r7]
_080E4FF6:
	subs r1, r1, r0
_080E4FF8:
	cmp sb, r1
	bhi _080E507E
	movs r0, #2
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bge _080E5006
	rsbs r1, r1, #0
_080E5006:
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	movs r1, #0
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _080E5026
	strh r1, [r4]
	strh r1, [r4, #2]
	strh r1, [r4, #4]
	movs r0, #1
	b _080E5080
_080E5026:
	mov r1, r8
	ldrh r0, [r1, #0x10]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	ldr r3, _080E5090 @ =0xFFFF0000
	ldr r2, _080E5094 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldrh r0, [r1, #0x14]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r1, #0x52
	orrs r0, r1
	ands r0, r2
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, r8
	adds r0, #8
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #8
	movs r3, #0xc
	bl FUN_080dbcec
	movs r2, #0x10
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080E507E:
	movs r0, #0
_080E5080:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080E5090: .4byte 0xFFFF0000
_080E5094: .4byte 0x0000FFFF
