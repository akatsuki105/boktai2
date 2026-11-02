	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrh r2, [r5]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0808846C
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0, #4]
	ldrh r5, [r5, #4]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08088468 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	b _080884DA
	.align 2, 0
_08088468: .4byte 0xFFFF0000
_0808846C:
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0808848C
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r1, r2, r0
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, #0
	mov r1, sp
	b _080884DA
_0808848C:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r1, r2, r0
	mov r0, sp
	strh r1, [r0]
	mov r6, sp
	adds r0, r4, #0
	mov r1, sp
	adds r2, r7, #0
	bl Coffin_CanMoveTo
	cmp r0, #0
	beq _080884E4
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	ldrh r0, [r5, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r4, #0
	mov r1, sp
	adds r2, r7, #0
	bl Coffin_CanMoveTo
	cmp r0, #0
	beq _080884E4
	mov r1, sp
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, #0
_080884DA:
	adds r2, r7, #0
	bl Coffin_CanMoveTo
	cmp r0, #0
	bne _080884E8
_080884E4:
	movs r0, #0
	b _080884EA
_080884E8:
	movs r0, #1
_080884EA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
