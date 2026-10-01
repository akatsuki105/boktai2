	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08085240
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085238 @ =0xFFFF0000
	mov sb, r1
	mov r2, sb
	ands r2, r6
	orrs r2, r0
	str r2, [sp]
	adds r6, r2, #0
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r1, _0808523C @ =0x0000FFFF
	adds r2, r6, #0
	ands r2, r1
	adds r6, r2, #0
	orrs r6, r0
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sb
	ands r1, r7
	adds r7, r1, #0
	orrs r7, r0
	b _08085246
	.align 2, 0
_08085238: .4byte 0xFFFF0000
_0808523C: .4byte 0x0000FFFF
_08085240:
	ldr r0, _08085298 @ =0xFFFF0000
	movs r6, #0
	ands r7, r0
_08085246:
	movs r2, #0xa8
	add r2, r8
	mov sl, r2
	movs r2, #0
	movs r3, #0
	movs r0, #1
	mov r1, sl
	strh r0, [r1]
	movs r1, #0xaa
	add r1, r8
	mov sb, r1
	strh r0, [r1]
	mov r1, r8
	adds r1, #0xb4
	movs r0, #0x50
	strb r0, [r1]
	mov r0, r8
	adds r0, #0xb5
	strb r2, [r0]
	subs r0, #9
	strh r3, [r0]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	mov r2, sl
	str r2, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	cmp r0, #0
	beq _0808529C
	bl VM_GetValue
	mov r1, r8
	adds r1, #0xae
	strb r0, [r1]
	bl VM_GetValue
	mov r1, r8
	adds r1, #0xaf
	b _080852A8
	.align 2, 0
_08085298: .4byte 0xFFFF0000
_0808529C:
	mov r1, r8
	adds r1, #0xae
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xc
_080852A8:
	strb r0, [r1]
	mov r4, r8
	adds r4, #0x18
	mov r5, r8
	adds r5, #0x44
	ldr r2, _08085368 @ =0x00003641
	mov sl, r2
	adds r0, r5, #0
	mov r1, sl
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	movs r0, #0
	strh r0, [r4, #0x10]
	ldr r1, [sp, #8]
	ldrh r0, [r1]
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	movs r2, #2
	mov sb, r2
	mov r0, sb
	strb r0, [r4, #7]
	str r6, [r4, #0x1c]
	str r7, [r4, #0x20]
	adds r4, #0x48
	adds r5, #0x48
	adds r0, r5, #0
	mov r1, sl
	bl Video_GetAuxSprite
	ldr r2, _0808536C @ =0x00000203
	adds r0, r4, #0
	adds r1, r5, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	movs r0, #1
	strh r0, [r4, #0x10]
	ldr r1, [sp, #0xc]
	ldrh r0, [r1]
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	mov r2, sb
	strb r2, [r4, #7]
	str r6, [r4, #0x1c]
	str r7, [r4, #0x20]
	mov r0, r8
	adds r0, #0xc0
	str r6, [r0]
	str r7, [r0, #4]
	mov r1, r8
	adds r1, #0xc8
	str r6, [r1]
	str r7, [r1, #4]
	mov r2, r8
	adds r2, #0xca
	ldrh r0, [r2]
	subs r0, #0x40
	strh r0, [r2]
	ldrh r0, [r1]
	subs r0, #0x2d
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	subs r0, #0x2d
	strh r0, [r1]
	mov r0, r8
	bl FUN_08084bb0
	mov r0, r8
	movs r1, #0
	bl FUN_08084c30
	ldr r0, _08085370 @ =0x03002BFC
	mov r1, r8
	str r1, [r0]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08085368: .4byte 0x00003641
_0808536C: .4byte 0x00000203
_08085370: .4byte 0x03002BFC
