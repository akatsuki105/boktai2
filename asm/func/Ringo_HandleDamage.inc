	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r7, r0, #0
	mov sb, r7
	adds r0, #0x48
	str r0, [sp, #0x28]
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x2c]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r0, #0
	ldrsh r1, [r2, r0]
	str r1, [sp, #0x20]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r4, r7, r1
	ldrb r0, [r4]
	str r0, [sp, #0x24]
	adds r1, #1
	adds r3, r7, r1
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
	strb r1, [r4]
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x30]
	ldrh r0, [r2]
	cmp r0, #0
	beq _08035AF8
	b _08035C04
_08035AF8:
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08035B06
	b _08035C0A
_08035B06:
	adds r0, r7, #0
	bl FUN_080299e0
	cmp r0, #0
	beq _08035C0A
	ldr r0, _08035BE8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08035BEC @ =0x00000942
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	adds r0, #0x92
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #5
	str r0, [sp, #0x20]
	ldr r3, _08035BF0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0xa4
	orrs r0, r2
	ldr r1, _08035BF4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	ldr r6, _08035BF8 @ =0x0203B400
	ldr r1, _08035BFC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r5, _08035C00 @ =0x000003FF
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r2, #3
	mov r8, r2
	ands r1, r2
	adds r1, #2
	adds r0, #1
	ands r0, r5
	ldr r2, _08035BFC @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #0x14
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sl, r2
	str r1, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	movs r1, #3
	add r2, sp, #0x10
	bl EmitSmoke
	ldr r1, _08035BFC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	mov r2, r8
	ands r1, r2
	adds r1, #2
	adds r0, #1
	ands r0, r5
	ldr r2, _08035BFC @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #0x14
	str r1, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	movs r1, #3
	add r2, sp, #0x10
	bl EmitSmoke
	movs r0, #0x3c
	ldr r1, [sp, #0x30]
	strh r0, [r1]
	b _08035C0A
	.align 2, 0
_08035BE8: .4byte 0x030046A0
_08035BEC: .4byte 0x00000942
_08035BF0: .4byte 0xFFFF0000
_08035BF4: .4byte 0x0000FFFF
_08035BF8: .4byte 0x0203B400
_08035BFC: .4byte 0x030046B8
_08035C00: .4byte 0x000003FF
_08035C04:
	subs r0, #1
	ldr r2, [sp, #0x30]
	strh r0, [r2]
_08035C0A:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	bgt _08035C12
	b _08035E44
_08035C12:
	adds r1, r7, #0
	adds r1, #0x90
	ldrh r0, [r1]
	ldr r2, [sp, #0x20]
	subs r3, r0, r2
	strh r3, [r1]
	movs r0, #0
	mov sl, r0
	movs r0, #0x82
	lsls r0, r0, #4
	add r0, sb
	ldr r2, [r0]
	adds r4, r1, #0
	mov r8, r0
	cmp r2, #0
	beq _08035C88
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x11
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, r1
	bgt _08035C9C
	ldr r0, _08035C7C @ =0x00000FD4
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08035C9C
	strh r1, [r4]
	adds r0, r7, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _08035C9C
	ldr r2, _08035C80 @ =0x00000FD8
	add r2, sb
	movs r0, #0xc5
	lsls r0, r0, #2
	add r0, sb
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _08035C84 @ =0x00000FD7
	add r1, sb
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #1
	mov sl, r0
	b _08035C9C
	.align 2, 0
_08035C7C: .4byte 0x00000FD4
_08035C80: .4byte 0x00000FD8
_08035C84: .4byte 0x00000FD7
_08035C88:
	adds r0, r7, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _08035C9C
	lsls r0, r3, #0x10
	cmp r0, #0
	bgt _08035C9C
	movs r0, #1
	strh r0, [r4]
_08035C9C:
	movs r1, #0xc4
	lsls r1, r1, #1
	add r1, sb
	movs r6, #0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #1
	add r1, sb
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #2
	add r0, sb
	movs r1, #0x84
	lsls r1, r1, #3
	add r1, sb
	str r1, [r0]
	movs r0, #0xe7
	lsls r0, r0, #2
	add r0, sb
	str r1, [r0]
	ldr r3, _08035D34 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08035D38 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r3, [sp, #0x28]
	adds r3, #8
	str r1, [sp]
	movs r5, #1
	str r5, [sp, #4]
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x20]
	movs r2, #0
	bl CreateDamageNumber
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _08035D6C
	strh r6, [r4]
	movs r2, #2
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, r8
	ldr r0, [r2]
	cmp r0, #0
	beq _08035D44
	ldr r1, _08035D3C @ =dainn_08032f18
	movs r0, #0x22
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r0, #0x1d
	strb r5, [r0]
	ldr r0, _08035D40 @ =0x000003CD
	bl PlaySound_0824078c
	b _08035E3C
	.align 2, 0
_08035D34: .4byte 0xFFFF0000
_08035D38: .4byte 0x0000FFFF
_08035D3C: .4byte dainn_08032f18
_08035D40: .4byte 0x000003CD
_08035D44:
	ldr r1, _08035D68 @ =FUN_08032e1c
	movs r0, #0x21
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r0, #0x1d
	strb r5, [r0]
	movs r0, #0xd4
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _08035E3C
	.align 2, 0
_08035D68: .4byte FUN_08032e1c
_08035D6C:
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r7, #0
	adds r0, #0x98
	ldr r2, [r0]
	orrs r2, r1
	str r2, [r0]
	adds r4, r0, #0
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _08035D8A
	movs r0, #0x80
	lsls r0, r0, #0x10
	orrs r2, r0
	str r2, [r4]
_08035D8A:
	ldr r1, _08035DD4 @ =0x00000874
	add r1, sb
	ldrh r0, [r1]
	subs r0, #0x28
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08035D9C
	strh r6, [r1]
_08035D9C:
	movs r2, #0x87
	lsls r2, r2, #4
	add r2, sb
	ldrh r0, [r2]
	adds r0, #0x64
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _08035DD8 @ =0x02570000
	cmp r0, r1
	bls _08035DB6
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r2]
_08035DB6:
	movs r0, #8
	movs r1, #0xc5
	lsls r1, r1, #1
	add r1, sb
	strb r0, [r1]
	ldr r0, _08035DDC @ =0x00000FD4
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035DE0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_0824078c
	b _08035E14
	.align 2, 0
_08035DD4: .4byte 0x00000874
_08035DD8: .4byte 0x02570000
_08035DDC: .4byte 0x00000FD4
_08035DE0:
	adds r0, r7, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _08035E0C
	mov r1, r8
	ldr r0, [r1]
	cmp r0, #0
	beq _08035E00
	ldr r0, _08035DFC @ =0x0000030D
	bl PlaySound_0824078c
	b _08035E14
	.align 2, 0
_08035DFC: .4byte 0x0000030D
_08035E00:
	ldr r0, _08035E08 @ =0x0000034F
	bl PlaySound_0824078c
	b _08035E14
	.align 2, 0
_08035E08: .4byte 0x0000034F
_08035E0C:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08035E14:
	mov r2, sl
	cmp r2, #0
	beq _08035E44
	movs r3, #1
	ldr r0, [r4]
	orrs r0, r3
	str r0, [r4]
	ldr r2, _08035E40 @ =FUN_08032acc
	movs r0, #0x1f
	adds r4, r7, #0
	adds r4, #0xa3
	movs r1, #0
	strb r0, [r4]
	adds r0, r7, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
_08035E3C:
	movs r0, #1
	b _08035E46
	.align 2, 0
_08035E40: .4byte FUN_08032acc
_08035E44:
	movs r0, #0
_08035E46:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
