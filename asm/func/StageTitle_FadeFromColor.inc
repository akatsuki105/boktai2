	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	movs r0, #0xb2
	lsls r0, r0, #2
	add r0, r8
	ldrh r7, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r7, r0
	ble _0801060C
	adds r7, r0, #0
_0801060C:
	subs r0, r0, r7
	mov ip, r0
	ldr r0, _0801070C @ =0x000002C6
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r1, r0
	str r1, [sp]
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r2, r0
	str r2, [sp, #4]
	movs r3, #0xf8
	lsls r3, r3, #7
	ands r3, r0
	str r3, [sp, #8]
	movs r1, #0
	movs r0, #0
	ldr r4, _08010710 @ =0x000002C2
	add r4, r8
	str r4, [sp, #0xc]
	movs r2, #0xb1
	lsls r2, r2, #2
	add r2, r8
	str r2, [sp, #0x10]
_0801063E:
	ldr r3, [sp, #0xc]
	ldrh r6, [r3]
	adds r4, r1, #0
	adds r4, #0x10
	str r4, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r6, r0
	bge _080106CA
	mov r2, r8
	ldr r2, [r2, #0x24]
	mov sl, r2
	mov r3, r8
	ldr r3, [r3, #0x20]
	mov sb, r3
	adds r0, r6, r1
	lsls r5, r0, #1
_08010664:
	mov r4, sl
	adds r0, r4, r5
	mov r1, sb
	adds r1, r1, r5
	str r1, [sp, #0x1c]
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r3, [sp]
	mov r0, ip
	muls r0, r3, r0
	adds r2, r2, r0
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r7, r3
	ldr r4, [sp, #4]
	mov r0, ip
	muls r0, r4, r0
	adds r3, r3, r0
	movs r0, #0xf8
	lsls r0, r0, #0xa
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r7, r0
	ldr r4, [sp, #8]
	mov r1, ip
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #0xf
	ands r0, r1
	orrs r2, r3
	orrs r2, r0
	asrs r2, r2, #8
	ldr r0, [sp, #0x1c]
	strh r2, [r0]
	adds r5, #2
	adds r6, #1
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	cmp r6, r1
	blt _08010664
_080106CA:
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	cmp r0, #1
	ble _0801063E
	movs r2, #0xb2
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _080106EE
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	str r0, [r1]
	strh r0, [r2]
_080106EE:
	ldr r0, _08010714 @ =0x000002CA
	add r0, r8
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801070C: .4byte 0x000002C6
_08010710: .4byte 0x000002C2
_08010714: .4byte 0x000002CA
