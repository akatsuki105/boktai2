	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r1, #8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D6D4A
	movs r0, #1
	b _081D6D4C
_081D6D4A:
	movs r0, #0
_081D6D4C:
	cmp r0, #0
	beq _081D6D52
	b _081D6EA8
_081D6D52:
	ldr r1, _081D6D70 @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6D74
	movs r2, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	bne _081D6D90
	b _081D6D94
	.align 2, 0
_081D6D70: .4byte 0x00000109
_081D6D74:
	movs r1, #0x10
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _081D6D9A
	movs r2, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081D6D94
_081D6D90:
	movs r0, #1
	b _081D6D96
_081D6D94:
	movs r0, #0
_081D6D96:
	cmp r0, #0
	beq _081D6DA6
_081D6D9A:
	movs r1, #0
	strh r1, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	b _081D6EA8
_081D6DA6:
	movs r1, #8
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081D6E80
	adds r1, r7, #0
	adds r1, #0x43
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081D6DEC @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D6DF4
	ldr r2, _081D6DF0 @ =0x00000105
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D6E02
	adds r0, r5, #0
	adds r0, #0x9c
	str r0, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
	movs r0, #3
	strb r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081D6E2A
	.align 2, 0
_081D6DEC: .4byte 0x00000109
_081D6DF0: .4byte 0x00000105
_081D6DF4:
	cmp r0, #1
	bne _081D6E2A
	ldr r0, _081D6E08 @ =0x00000105
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D6E0C
_081D6E02:
	subs r0, #1
	strb r0, [r4]
	b _081D6E2A
	.align 2, 0
_081D6E08: .4byte 0x00000105
_081D6E0C:
	adds r0, r5, #0
	adds r0, #0x9c
	str r0, [sp]
	movs r0, #2
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
	movs r0, #2
	strb r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081D6E2A:
	movs r1, #4
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D6E3A
	movs r0, #1
	b _081D6E3C
_081D6E3A:
	movs r0, #0
_081D6E3C:
	cmp r0, #0
	beq _081D6E80
	ldr r1, _081D6E64 @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6E68
	adds r1, r5, #0
	adds r1, #0xf4
	ldrh r0, [r1]
	subs r0, #0xc8
	strh r0, [r1]
	adds r2, r0, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D6E5E
	movs r2, #0
_081D6E5E:
	strh r2, [r1]
	b _081D6E80
	.align 2, 0
_081D6E64: .4byte 0x00000109
_081D6E68:
	adds r2, r5, #0
	adds r2, #0xf4
	ldrh r0, [r2]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r2]
	adds r1, r0, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D6E7E
	movs r1, #0
_081D6E7E:
	strh r1, [r2]
_081D6E80:
	ldr r2, _081D6EB4 @ =0x00000109
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6EA8
	ldr r2, [r6, #0x4c]
	cmp r2, #0
	beq _081D6EA8
	ldr r3, [r6, #0x48]
	cmp r3, #0
	beq _081D6EA8
	movs r1, #0x10
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081D6EA8
	adds r0, r6, #0
	adds r1, r7, #0
	bl _call_via_r3
_081D6EA8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6EB4: .4byte 0x00000109
