	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov sb, r0
	str r1, [sp, #0x10]
	mov r8, r2
	mov sl, r3
	ldr r0, _08234120 @ =0x030046A4
	ldr r4, [r0]
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _082340E8
	b _082341F6
_082340E8:
	movs r3, #0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0823411C
	cmp r1, #0
	blt _0823411C
	ldr r0, _08234124 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0823411C
	ldr r0, _08234128 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08234130
_0823411C:
	movs r6, #0
	b _0823413C
	.align 2, 0
_08234120: .4byte 0x030046A4
_08234124: .4byte 0x030046A8
_08234128: .4byte 0x030046AC
_0823412C:
	movs r0, #1
	b _082341F8
_08234130:
	lsls r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r6, r0, r2
_0823413C:
	movs r7, #0
	cmp r7, r8
	bge _082341F6
	add r5, sp, #8
_08234144:
	adds r0, r5, #0
	mov r1, sp
	ldr r2, [sp, #0x10]
	bl FUN_08233d50
	adds r3, r0, #0
	cmp r3, #1
	ble _08234192
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08234178
	cmp r1, #0
	blt _08234178
	ldr r0, _0823417C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08234178
	ldr r0, _08234180 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08234184
_08234178:
	movs r6, #0
	b _08234192
	.align 2, 0
_0823417C: .4byte 0x030046A8
_08234180: .4byte 0x030046AC
_08234184:
	ldr r0, _082341A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_08234192:
	adds r4, r5, #0
	adds r0, r6, #0
	movs r1, #1
	str r3, [sp, #0x14]
	bl FUN_08234224
	ldr r3, [sp, #0x14]
	cmp r0, #0
	beq _082341AC
	adds r0, #4
	b _082341B8
	.align 2, 0
_082341A8: .4byte 0x030046A4
_082341AC:
	ldr r0, _082341CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_082341B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _082341D0
	cmp r2, #2
	beq _082341D4
	b _082341D8
	.align 2, 0
_082341CC: .4byte 0x030046A4
_082341D0:
	ldrb r0, [r4, #4]
	b _082341D6
_082341D4:
	ldrb r0, [r4]
_082341D6:
	subs r1, r1, r0
_082341D8:
	mov r4, sb
	movs r2, #2
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, sl
	bge _082341F6
	cmp r3, #1
	beq _0823412C
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	adds r7, #1
	cmp r7, r8
	blt _08234144
_082341F6:
	movs r0, #0
_082341F8:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
