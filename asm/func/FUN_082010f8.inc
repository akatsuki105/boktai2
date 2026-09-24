	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x64
	mov sl, r0
	str r1, [sp, #0x54]
	mov r0, sp
	adds r0, #0x3c
	str r0, [sp, #0x60]
	cmp r1, #0
	bne _082011CA
	ldr r0, _082013A4 @ =0x00000694
	add r0, sl
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r0, _082013A8 @ =0x00000696
	add r0, sl
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xd3
	lsls r0, r0, #3
	add r0, sl
	movs r7, #0
	ldrsh r0, [r0, r7]
	subs r1, #0x64
	ldr r3, [sp, #0x60]
	strh r2, [r3]
	strh r1, [r3, #2]
	strh r0, [r3, #4]
	add r6, sp, #0x44
	add r5, sp, #0x4c
	mov r0, sl
	adds r0, #0x44
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	movs r7, #7
	mov sb, r7
_08201146:
	str r1, [r0]
	str r2, [r0, #4]
	adds r0, #0x2c
	movs r3, #1
	rsbs r3, r3, #0
	add sb, r3
	mov r7, sb
	cmp r7, #0
	bge _08201146
	movs r4, #0
	mov r0, sl
	str r4, [r0, #0x1c]
	str r4, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r6, #0
	ldr r2, _082013AC @ =0x05000002
	bl CpuSet
	ldr r0, _082013A4 @ =0x00000694
	add r0, sl
	movs r1, #0
	ldrsh r3, [r0, r1]
	ldr r0, _082013A8 @ =0x00000696
	add r0, sl
	movs r7, #0
	ldrsh r2, [r0, r7]
	movs r0, #0xd3
	lsls r0, r0, #3
	add r0, sl
	movs r7, #0
	ldrsh r1, [r0, r7]
	adds r3, #0x40
	subs r2, #0x20
	adds r1, #0x40
	add r0, sp, #0x4c
	strh r3, [r0]
	strh r2, [r5, #2]
	strh r1, [r5, #4]
	ldr r2, _082013B0 @ =0x0000F422
	ldr r3, _082013B4 @ =0x0000121B
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _082013B8 @ =0x00000237
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_081f22c0
	movs r0, #0xdb
	lsls r0, r0, #1
	bl PlaySound_082406e0
_082011CA:
	movs r0, #0
	str r0, [sp, #0x58]
	mov sb, r0
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, sl
	mov r1, sl
	adds r1, #0x46
_082011DA:
	ldrh r0, [r1]
	adds r0, #0x1c
	mov r3, sb
	subs r0, r0, r3
	strh r0, [r1]
	adds r1, #0x2c
	movs r7, #1
	add sb, r7
	mov r0, sb
	cmp r0, #6
	ble _082011DA
	movs r1, #0
	mov sb, r1
	ldr r3, [sp, #0x60]
	mov r8, r3
	adds r6, r2, #0
	movs r7, #0xae
	lsls r7, r7, #1
	add r7, sl
	mov r0, sp
	adds r0, #0x3c
	str r0, [sp, #0x5c]
_08201206:
	ldrh r0, [r6, #0x1c]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	ldr r1, [sp, #0x5c]
	strh r0, [r1]
	ldrh r0, [r6, #0x1e]
	ldrh r1, [r7, #0x1e]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	ldrh r0, [r6, #0x20]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r3, [sp, #0x5c]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov r3, r8
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r3, r1, r0
	ldr r1, _082013BC @ =0x085AE7C8
	movs r0, #7
	mov r2, sb
	subs r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _082012BC
	ldr r0, _082013C0 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r5, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _082012A0
	ldr r3, [sp, #0x60]
	movs r1, #0
	ldrsh r0, [r3, r1]
	muls r0, r5, r0
	adds r1, r4, #0
	bl Div
	ldr r2, [sp, #0x5c]
	strh r0, [r2]
	mov r3, r8
	movs r1, #2
	ldrsh r0, [r3, r1]
	muls r0, r5, r0
	adds r1, r4, #0
	bl Div
	mov r2, r8
	strh r0, [r2, #2]
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r5, r0
	adds r1, r4, #0
	bl Div
	mov r1, r8
	strh r0, [r1, #4]
_082012A0:
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r6, #0x1c]
	mov r1, r8
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #0x1e]
	adds r0, r0, r2
	strh r0, [r6, #0x1e]
	ldrh r0, [r1, #4]
	ldrh r3, [r7, #0x20]
	adds r0, r0, r3
	strh r0, [r6, #0x20]
_082012BC:
	ldr r0, _082013A8 @ =0x00000696
	add r0, sl
	movs r2, #0x1e
	ldrsh r1, [r6, r2]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	blt _082012E2
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	ldr r0, [sp, #0x58]
	adds r0, #1
	str r0, [sp, #0x58]
_082012E2:
	subs r7, #0x2c
	subs r6, #0x2c
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #6
	ble _08201206
	ldr r3, [sp, #0x58]
	cmp r3, #6
	ble _0820131E
	movs r2, #0xae
	lsls r2, r2, #1
	add r2, sl
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	movs r2, #0xbc
	lsls r2, r2, #1
	add r2, sl
	ldr r0, _082013A4 @ =0x00000694
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r7, sl
	ldr r0, [r7, #0x1c]
	adds r0, #1
	str r0, [r7, #0x1c]
_0820131E:
	mov r1, sl
	ldr r0, [r1, #0x1c]
	cmp r0, #3
	bls _0820132E
	ldr r1, _082013C4 @ =0x000006D9
	add r1, sl
	movs r0, #1
	strb r0, [r1]
_0820132E:
	ldr r0, [sp, #0x54]
	movs r1, #8
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	bne _08201394
	ldr r2, _082013C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _082013CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _082013D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0x7f
	ands r2, r0
	ldr r0, _082013A4 @ =0x00000694
	add r0, sl
	movs r1, #0xc
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #0x20
	str r1, [sp, #0x10]
	movs r1, #1
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r1, _082013B0 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _082013B4 @ =0x0000121B
	str r1, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl FUN_081ee53c
_08201394:
	add sp, #0x64
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082013A4: .4byte 0x00000694
_082013A8: .4byte 0x00000696
_082013AC: .4byte 0x05000002
_082013B0: .4byte 0x0000F422
_082013B4: .4byte 0x0000121B
_082013B8: .4byte 0x00000237
_082013BC: .4byte 0x085AE7C8
_082013C0: .4byte 0x085AE7B8
_082013C4: .4byte 0x000006D9
_082013C8: .4byte 0x030046B8
_082013CC: .4byte 0x000003FF
_082013D0: .4byte 0x0203B400
