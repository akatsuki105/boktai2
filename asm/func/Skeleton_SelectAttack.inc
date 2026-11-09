	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104C4E
	b _08104D66
_08104C4E:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r6, [r0]
	adds r1, #0xe4
	adds r0, r5, r1
	adds r2, #0x68
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08104D44
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	adds r3, #0xc
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	ldrb r1, [r5, #5]
	subs r2, r0, r1
	cmp r2, #0x80
	ble _08104CB0
	ldr r0, _08104CAC @ =0xFFFFFF00
	adds r2, r2, r0
	b _08104CBE
	.align 2, 0
_08104CAC: .4byte 0xFFFFFF00
_08104CB0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08104CBE
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
_08104CBE:
	cmp r2, #0
	bge _08104CC4
	rsbs r2, r2, #0
_08104CC4:
	ldr r3, _08104CE4 @ =0x000001FD
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r2, r0
	bge _08104D20
	ldr r1, _08104CE8 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08104CEC
	adds r0, r5, #0
	adds r1, r6, #0
	bl Skeleton_SelectAttackNormal
	b _08104D06
	.align 2, 0
_08104CE4: .4byte 0x000001FD
_08104CE8: .4byte 0x000001DF
_08104CEC:
	cmp r0, #6
	bne _08104CFA
	adds r0, r5, #0
	adds r1, r6, #0
	bl Skeleton_SelectAttackFencer
	b _08104D06
_08104CFA:
	cmp r0, #7
	bne _08104D0C
	adds r0, r5, #0
	adds r1, r6, #0
	bl Skeleton_SelectAttackArcher
_08104D06:
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08104D66
_08104D0C:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08104D32
	b _08104D36
_08104D20:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104D36
_08104D32:
	movs r0, #1
	b _08104D38
_08104D36:
	movs r0, #0
_08104D38:
	cmp r0, #0
	bne _08104D66
	adds r0, r5, #0
	bl Skeleton_RetreatOrChase
	b _08104D66
_08104D44:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104D5A
	movs r0, #1
	b _08104D5C
_08104D5A:
	movs r0, #0
_08104D5C:
	cmp r0, #0
	bne _08104D66
	adds r0, r5, #0
	bl Skeleton_RetreatOrChase
_08104D66:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
