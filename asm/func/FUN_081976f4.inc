	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197720
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197722
_08197720:
	movs r0, #0
_08197722:
	cmp r0, #0
	beq _081977B0
	movs r0, #0x60
	adds r0, r0, r4
	mov ip, r0
	ldr r1, _08197834 @ =FUN_08196580
	mov r8, r1
	ldr r3, _08197838 @ =FUN_081958b4
	mov sb, r3
	ldr r0, _0819783C @ =0x00000AFC
	adds r7, r4, r0
	ldr r1, _08197840 @ =0x00000AFE
	adds r6, r4, r1
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r5, r4, r3
	adds r1, r4, #0
	adds r1, #0x66
	subs r0, #0x16
	adds r3, r4, r0
	movs r2, #3
_0819774C:
	ldrh r0, [r7]
	strh r0, [r1, #0x16]
	ldrh r0, [r6]
	strh r0, [r1, #0x18]
	ldrh r0, [r5]
	strh r0, [r1, #0x1a]
	ldrb r0, [r3]
	strb r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _0819774C
	movs r3, #2
	rsbs r3, r3, #0
	mov r1, ip
	adds r2, r1, #0
	adds r2, #0x84
_0819776E:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _0819776E
	ldr r1, _08197844 @ =0x00000C48
	adds r0, r4, r1
	mov r3, r8
	str r3, [r0]
	ldr r1, _08197848 @ =0x0000044C
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x89
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	ldr r3, _0819784C @ =0x00000CCA
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	mov r3, sb
	str r3, [r0]
	adds r1, #0x63
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _08197850 @ =0x0000016F
	bl PlaySound_082406e0
_081977B0:
	ldr r3, _08197844 @ =0x00000C48
	adds r0, r4, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081977C0
	adds r0, r4, #0
	bl _call_via_r1
_081977C0:
	ldr r1, _08197854 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08197826
	movs r2, #3
	adds r5, r4, #0
	adds r5, #0x7c
	adds r6, r4, #0
	adds r6, #0x7e
	adds r7, r4, #0
	adds r7, #0x80
	movs r3, #0x66
	adds r3, r3, r4
	mov ip, r3
	adds r3, r4, #0
	adds r3, #0xbe
	adds r1, r4, #0
	adds r1, #0xd4
_081977EA:
	ldrh r0, [r1]
	strh r0, [r1, #0x2c]
	ldrh r0, [r1, #2]
	strh r0, [r1, #0x2e]
	ldrh r0, [r1, #4]
	strh r0, [r1, #0x30]
	ldrb r0, [r3]
	strb r0, [r1, #0x16]
	subs r3, #0x2c
	subs r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bgt _081977EA
	ldr r1, _0819783C @ =0x00000AFC
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r5]
	ldr r3, _08197840 @ =0x00000AFE
	adds r0, r4, r3
	ldrh r0, [r0]
	strh r0, [r6]
	adds r1, #4
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r7]
	subs r3, #0x18
	adds r0, r4, r3
	ldrb r0, [r0]
	mov r1, ip
	strb r0, [r1]
_08197826:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197834: .4byte FUN_08196580
_08197838: .4byte FUN_081958b4
_0819783C: .4byte 0x00000AFC
_08197840: .4byte 0x00000AFE
_08197844: .4byte 0x00000C48
_08197848: .4byte 0x0000044C
_0819784C: .4byte 0x00000CCA
_08197850: .4byte 0x0000016F
_08197854: .4byte 0x00000CEC
