	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	str r1, [sp, #8]
	mov sb, r2
	mov sl, r3
	ldr r0, [sp, #0x2c]
	mov r8, r0
	ldr r5, [sp, #0x44]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EADA4 @ =0x030047A4
	ldr r1, _081EADA8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EADA0
	movs r1, #4
	ldr r0, _081EADAC @ =0x03002BC0
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081EADA0
	ldr r0, _081EADB0 @ =0x030001C0
	ldr r0, [r0]
	cmp r0, #0
	beq _081EADA0
	bl FUN_081eab78
	adds r7, r0, #0
	cmp r7, #0
	bne _081EADB4
_081EADA0:
	movs r0, #0
	b _081EAED8
	.align 2, 0
_081EADA4: .4byte 0x030047A4
_081EADA8: .4byte 0x030047A0
_081EADAC: .4byte 0x03002BC0
_081EADB0: .4byte 0x030001C0
_081EADB4:
	adds r2, r7, #0
	adds r2, #0xd0
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r1, sb
	strh r1, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [sp, #0x40]
	strh r0, [r1]
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #1
	mov sb, r1
	mov r1, sb
	strh r1, [r0]
	adds r6, r7, #0
	adds r6, #0x60
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823b400
	adds r4, r7, #0
	adds r4, #0xa4
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823b46c
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	mov r0, sb
	ands r5, r0
	cmp r5, #0
	beq _081EAEB6
	mov r1, sl
	cmp r1, #0
	bne _081EAE74
	mov r0, r8
	cmp r0, #1
	beq _081EAE54
	cmp r0, #1
	bgt _081EAE3E
	cmp r0, #0
	beq _081EAE46
	b _081EAEB0
_081EAE3E:
	mov r1, r8
	cmp r1, #2
	beq _081EAE60
	b _081EAEB0
_081EAE46:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE50 @ =0x085AE498
	adds r0, #0x20
	b _081EAE66
	.align 2, 0
_081EAE50: .4byte 0x085AE498
_081EAE54:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE5C @ =0x085AE4A0
	adds r0, #0x64
	b _081EAE66
	.align 2, 0
_081EAE5C: .4byte 0x085AE4A0
_081EAE60:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE70 @ =0x085AE4A8
	adds r0, #0xc8
_081EAE66:
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #0xc]
	b _081EAEB0
	.align 2, 0
_081EAE70: .4byte 0x085AE4A8
_081EAE74:
	mov r0, r8
	cmp r0, #1
	beq _081EAE98
	cmp r0, #1
	bgt _081EAE84
	cmp r0, #0
	beq _081EAE8C
	b _081EAEB0
_081EAE84:
	mov r1, r8
	cmp r1, #2
	beq _081EAEA4
	b _081EAEB0
_081EAE8C:
	ldrh r0, [r6, #8]
	ldr r1, _081EAE94 @ =0x085AE498
	adds r0, #0x20
	b _081EAEAA
	.align 2, 0
_081EAE94: .4byte 0x085AE498
_081EAE98:
	ldrh r0, [r6, #8]
	ldr r1, _081EAEA0 @ =0x085AE4A0
	adds r0, #0x64
	b _081EAEAA
	.align 2, 0
_081EAEA0: .4byte 0x085AE4A0
_081EAEA4:
	ldrh r0, [r6, #8]
	ldr r1, _081EAEE8 @ =0x085AE4A8
	adds r0, #0xc8
_081EAEAA:
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #8]
_081EAEB0:
	adds r0, r6, #0
	bl FUN_08002a48
_081EAEB6:
	ldr r0, [sp, #0x38]
	str r0, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	adds r0, r7, #0
	mov r1, sl
	mov r2, r8
	ldr r3, [sp, #0x34]
	bl FUN_081eabd0
	adds r0, r7, #0
	mov r1, sl
	mov r2, r8
	ldr r3, [sp, #0x30]
	bl FUN_081eace8
	adds r0, r7, #0
_081EAED8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EAEE8: .4byte 0x085AE4A8
