	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0813BF98 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813BF9C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813BF9E
	.align 2, 0
_0813BF98: .4byte 0x0000046C
_0813BF9C:
	movs r0, #0
_0813BF9E:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r3, r5, r1
	cmp r0, #0
	beq _0813C08E
	ldr r3, _0813C014 @ =FUN_0813ad34
	movs r2, #0x23
	ldr r0, _0813C018 @ =0x0000046D
	adds r1, r5, r0
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813C01C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	adds r0, r5, #0
	bl Curoro_ReleasePlayer
	ldr r2, _0813C020 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813C024 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0813C028 @ =0x0203B400
	adds r0, r0, r1
	ldrb r6, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r7, r2
	str r4, [sp]
	mov r0, sp
	ldr r2, _0813C02C @ =0x05000002
	bl CpuSet
	ldr r1, _0813C030 @ =gSineTable
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0813C034
	asrs r1, r0, #0xc
	b _0813C03A
	.align 2, 0
_0813C014: .4byte FUN_0813ad34
_0813C018: .4byte 0x0000046D
_0813C01C: .4byte 0x0000046B
_0813C020: .4byte 0x030046B8
_0813C024: .4byte 0x000003FF
_0813C028: .4byte 0x0203B400
_0813C02C: .4byte 0x05000002
_0813C030: .4byte gSineTable
_0813C034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813C03A:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xa
	strh r0, [r1]
	ldr r2, _0813C06C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0813C070
	asrs r1, r0, #0xc
	b _0813C076
	.align 2, 0
_0813C06C: .4byte gSineTable
_0813C070:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813C076:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r2, _0813C120 @ =0xFFEFFFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r3, r1, #0
_0813C08E:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x10
	ldr r1, [r3]
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	beq _0813C10C
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r1, r0
	str r1, [r3]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _0813C124 @ =0x05000002
	bl CpuSet
	movs r1, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r2, _0813C128 @ =0x00000469
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0813C12C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0813C130 @ =Enemy_ClearStateBegun
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0813C134 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r6, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_0813C10C:
	ldr r3, _0813C12C @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813C120: .4byte 0xFFEFFFFF
_0813C124: .4byte 0x05000002
_0813C128: .4byte 0x00000469
_0813C12C: .4byte 0x00000484
_0813C130: .4byte Enemy_ClearStateBegun
_0813C134: .4byte 0x0000046B
