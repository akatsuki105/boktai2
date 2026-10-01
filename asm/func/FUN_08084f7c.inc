	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0xaa
	ldrh r0, [r1]
	cmp r0, #0xc
	bhi _0808506C
	movs r7, #0
	movs r0, #0xc0
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xc4
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0xac
	adds r2, r2, r6
	mov sl, r2
_08084FA6:
	mov r3, sb
	movs r0, #0
	ldrsh r2, [r3, r0]
	ldr r1, _08085064 @ =0x03002BE0
	lsls r0, r7, #2
	adds r5, r0, r1
	ldr r4, [r5]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	mov r3, r8
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	adds r0, r2, #0
	cmp r2, #0
	bge _08084FCE
	rsbs r0, r2, #0
_08084FCE:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _08085038
	adds r0, r3, #0
	cmp r3, #0
	bge _08084FDE
	rsbs r0, r3, #0
_08084FDE:
	cmp r0, r1
	bgt _08085038
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bgt _08085038
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x64
	strh r0, [r1]
	ldr r0, [r5]
	ldr r1, _08085068 @ =0x000003D2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	adds r0, r2, #0
	adds r1, r3, #0
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r2, r3
	strb r0, [r2]
	ldr r0, [r5]
	movs r1, #0x1e
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
_08085038:
	adds r7, #1
	cmp r7, #1
	ble _08084FA6
	adds r0, r6, #0
	bl FUN_08084a14
	movs r0, #0
	mov r3, sl
	strh r0, [r3]
	ldr r0, [r6, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #0x18]
	ldr r0, [r6, #0x60]
	orrs r0, r1
	str r0, [r6, #0x60]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08084c30
	b _0808508C
	.align 2, 0
_08085064: .4byte 0x03002BE0
_08085068: .4byte 0x000003D2
_0808506C:
	subs r0, #0xc
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808508C
	movs r0, #1
	strh r0, [r1]
_0808508C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
