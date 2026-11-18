	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r7, #0
	movs r0, #0x84
	lsls r0, r0, #3
	adds r0, r0, r5
	mov sl, r0
	ldr r1, _08197220 @ =0x00000C64
	adds r1, r1, r5
	mov sb, r1
	ldr r2, _08197224 @ =0x00000424
	adds r2, r2, r5
	mov r8, r2
	movs r0, #0x80
	lsls r0, r0, #3
	adds r6, r5, r0
_081970E2:
	mov r2, sl
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	mov r2, sb
	ldr r0, [r2]
	muls r0, r1, r0
	movs r1, #0xf
	bl Div
	movs r1, #0x2c
	muls r1, r7, r1
	adds r4, r5, r1
	mov r2, sl
	ldrh r1, [r2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x7c
	strh r1, [r0]
	mov r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #4
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	mov r2, sb
	ldr r0, [r2]
	muls r0, r1, r0
	movs r1, #0xf
	bl Div
	mov r2, r8
	ldrh r1, [r2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x80
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0x68
	ldrb r0, [r1]
	adds r0, #3
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3f
	ble _08197146
	movs r0, #0x40
	strb r0, [r1]
_08197146:
	adds r6, #8
	adds r7, #1
	cmp r7, #3
	ble _081970E2
	ldr r6, _08197228 @ =0x00000CEC
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0819720E
	ldr r0, _08197220 @ =0x00000C64
	adds r1, r5, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0819720E
	adds r1, r5, #0
	adds r1, #0x4a
	str r1, [sp, #4]
	adds r2, r5, #0
	adds r2, #0x4b
	str r2, [sp]
	movs r6, #0x45
	adds r6, r6, r5
	mov ip, r6
	movs r0, #0x84
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r8, r0
	ldr r1, _08197224 @ =0x00000424
	adds r1, r5, r1
	str r1, [sp, #8]
	adds r2, #0x1d
	movs r3, #0
	movs r6, #0x40
	mov sl, r6
	adds r4, r5, #0
	adds r4, #0x60
	movs r0, #1
	mov sb, r0
	movs r7, #3
_0819719C:
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #0x14]
	ldr r6, [sp, #8]
	ldrh r0, [r6]
	strh r0, [r2, #0x18]
	mov r0, sl
	strb r0, [r2]
	adds r1, r4, r3
	ldr r0, [r1]
	mov r6, sb
	orrs r0, r6
	str r0, [r1]
	adds r2, #0x2c
	adds r3, #0x2c
	subs r7, #1
	cmp r7, #0
	bge _0819719C
	movs r0, #0xae
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0819722C @ =0x00000B9A
	adds r3, r5, r1
	ldrh r2, [r3]
	ldr r1, _08197230 @ =0x0000FFFB
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r6, _08197234 @ =0x00000BEA
	adds r2, r5, r6
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	movs r0, #1
	movs r1, #5
	ldr r2, [sp, #4]
	strb r0, [r2]
	ldr r6, [sp]
	strb r1, [r6]
	mov r2, ip
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r6, _08197238 @ =0x00000C38
	adds r0, r5, r6
	ldr r1, _0819723C @ =FUN_08197c30
	str r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r6, _08197240 @ =FUN_08196e54
	str r6, [r0]
_0819720E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197220: .4byte 0x00000C64
_08197224: .4byte 0x00000424
_08197228: .4byte 0x00000CEC
_0819722C: .4byte 0x00000B9A
_08197230: .4byte 0x0000FFFB
_08197234: .4byte 0x00000BEA
_08197238: .4byte 0x00000C38
_0819723C: .4byte FUN_08197c30
_08197240: .4byte FUN_08196e54
