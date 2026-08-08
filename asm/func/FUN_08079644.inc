	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r1, [r5, #0x34]
	ldrh r0, [r5, #0x2c]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _080796A8 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r6
	orrs r0, r1
	str r0, [sp]
	ldrh r0, [r5, #0x38]
	ldrh r1, [r5, #0x30]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r6
	orrs r1, r0
	str r1, [sp, #4]
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08079714
	ldr r1, _080796AC @ =0x00000392
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_081d553c
	adds r3, r0, #0
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r0, r1, #0
	subs r0, #0x64
	cmp r2, r0
	bgt _080796B0
	ldrh r0, [r3]
	subs r0, #0x64
	b _080796BC
	.align 2, 0
_080796A8: .4byte 0xFFFF0000
_080796AC: .4byte 0x00000392
_080796B0:
	adds r0, r1, #0
	adds r0, #0x64
	cmp r2, r0
	blt _080796C8
	ldrh r0, [r3]
	adds r0, #0x64
_080796BC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp]
	ands r1, r6
	orrs r1, r0
	str r1, [sp]
_080796C8:
	mov r0, sp
	movs r1, #4
	ldrsh r2, [r0, r1]
	movs r0, #4
	ldrsh r1, [r3, r0]
	adds r0, r1, #0
	subs r0, #0x64
	cmp r2, r0
	bgt _080796E0
	ldrh r0, [r3, #4]
	subs r0, #0x64
	b _080796EC
_080796E0:
	adds r0, r1, #0
	adds r0, #0x64
	cmp r2, r0
	blt _080796FA
	ldrh r0, [r3, #4]
	adds r0, #0x64
_080796EC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08079710 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
_080796FA:
	ldrh r1, [r5, #0x2c]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r1
	strh r0, [r5, #0x34]
	ldrh r1, [r5, #0x30]
	mov r0, sp
	ldrh r0, [r0, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x38]
	b _08079722
	.align 2, 0
_08079710: .4byte 0xFFFF0000
_08079714:
	mov r0, sp
	bl FUN_080795bc
	cmp r0, #0
	beq _08079722
	strh r4, [r5, #0x34]
	strh r4, [r5, #0x38]
_08079722:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
