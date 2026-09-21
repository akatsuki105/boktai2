	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08006254 @ =0x0300002C
	ldr r6, [r0]
	cmp r6, #0
	bne _080061AA
	b _080062C2
_080061AA:
	ldrb r0, [r7, #4]
	mov r8, r0
	ldr r4, [r6, #0x28]
	cmp r4, #0
	bne _080061B6
	b _080062C2
_080061B6:
	movs r1, #0
	mov sb, r1
_080061BA:
	ldrb r1, [r4, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0800624C
	ldrh r1, [r4, #4]
	ldr r0, _08006258 @ =0x000001FF
	cmp r1, r0
	bne _0800624C
	adds r3, r7, #0
	adds r3, #8
	ldr r2, [r4, #0x2c]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #8
	ldrsh r0, [r7, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080061E2
	rsbs r1, r1, #0
_080061E2:
	cmp r1, #0x5f
	bgt _08006210
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r5, #2
	ldrsh r0, [r3, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080061F6
	rsbs r1, r1, #0
_080061F6:
	cmp r1, #0x7f
	bgt _08006210
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0800620A
	rsbs r1, r1, #0
_0800620A:
	movs r0, #1
	cmp r1, #0x5f
	ble _08006212
_08006210:
	movs r0, #0
_08006212:
	cmp r0, #0
	beq _0800624C
	ldr r1, _0800625C @ =0x03002BE0
	mov r5, r8
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08006260
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08006260
	ldrb r0, [r4, #0x15]
	cmp r0, #1
	bne _08006260
	adds r5, r6, #0
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #0
	bne _0800624C
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xf
	strb r0, [r5]
_0800624C:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r4, [r0]
	b _080062BC
	.align 2, 0
_08006254: .4byte 0x0300002C
_08006258: .4byte 0x000001FF
_0800625C: .4byte 0x03002BE0
_08006260:
	mov r2, r8
	strb r2, [r4, #4]
	ldr r0, _080062B0 @ =0x0000010F
	bl PlaySound_0824078c
	ldr r0, _080062B4 @ =MapItem_UpdateOpen
	str r0, [r4, #0x44]
	mov r5, sb
	str r5, [r4, #0x18]
	strb r5, [r4, #9]
	ldr r0, [r4, #0x28]
	ldr r1, [r6, #0x1c]
	str r5, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
	ldr r0, _080062B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080062A2
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #2
	ldrsh r1, [r4, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _080062A4
_080062A2:
	movs r2, #1
_080062A4:
	ldrh r1, [r4, #0x30]
	adds r0, r4, #0
	bl MapItem_ExecScript
	movs r0, #1
	b _080062C4
	.align 2, 0
_080062B0: .4byte 0x0000010F
_080062B4: .4byte MapItem_UpdateOpen
_080062B8: .4byte 0x030047A4
_080062BC:
	cmp r4, #0
	beq _080062C2
	b _080061BA
_080062C2:
	movs r0, #0
_080062C4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
