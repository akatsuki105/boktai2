	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080F9C38 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F9C3C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F9C3E
	.align 2, 0
_080F9C38: .4byte 0x0000046C
_080F9C3C:
	movs r0, #0
_080F9C3E:
	cmp r0, #0
	beq _080F9C9C
	ldr r1, _080F9D58 @ =0x000005A4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0
	ldr r3, _080F9D5C @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _080F9D60 @ =0x0000046B
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r5, r4
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r5, r4
	subs r1, #0x81
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _080F9D64 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r0, _080F9D68 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _080F9D6C @ =0x00000482
	adds r0, r5, r2
	strh r3, [r0]
_080F9C9C:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _080F9CB4
	b _080F9E2C
_080F9CB4:
	ldr r0, _080F9D70 @ =0x00000484
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0x1e
	bne _080F9CD4
	ldr r1, _080F9D74 @ =0x000001DF
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_080f9bfc
_080F9CD4:
	ldr r0, [r4]
	cmp r0, #0x3c
	bgt _080F9CDC
	b _080F9E28
_080F9CDC:
	movs r1, #7
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _080F9D78 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _080F9D7C @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _080F9D70 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r2, [r0]
	adds r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	ldr r3, _080F9D60 @ =0x0000046B
	adds r0, r5, r3
	strb r6, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r2, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r6, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r0, [r2]
	strh r1, [r0, #6]
	ldr r1, _080F9D80 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	ldr r7, [r2]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080F9D84
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080F9DAA
	.align 2, 0
_080F9D58: .4byte 0x000005A4
_080F9D5C: .4byte 0x0000046D
_080F9D60: .4byte 0x0000046B
_080F9D64: .4byte 0xFEFFFFFF
_080F9D68: .4byte 0xFFFFFDFF
_080F9D6C: .4byte 0x00000482
_080F9D70: .4byte 0x00000484
_080F9D74: .4byte 0x000001DF
_080F9D78: .4byte 0x00000469
_080F9D7C: .4byte 0x0000046A
_080F9D80: .4byte 0x000004A4
_080F9D84:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080F9DA4
	cmp r0, #2
	beq _080F9DA0
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080F9DA0:
	movs r0, #1
	b _080F9DB4
_080F9DA4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_080F9DAA:
	ldr r1, _080F9DC8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080F9DB4:
	cmp r0, #0
	bne _080F9DD0
	ldr r4, _080F9DCC @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _080F9E2C
	.align 2, 0
_080F9DC8: .4byte 0xFFFFFDFF
_080F9DCC: .4byte 0x000005C4
_080F9DD0:
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F9E2C
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r1, _080F9E18 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldr r1, _080F9E1C @ =0xFFFFFDFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r3, [r0]
	ldr r2, _080F9E20 @ =0x0000021E
	adds r0, r5, r2
	strh r4, [r0]
	ldr r3, _080F9E24 @ =0x00000202
	adds r0, r5, r3
	strh r4, [r0]
	b _080F9E2C
	.align 2, 0
_080F9E18: .4byte 0xFEFFFFFF
_080F9E1C: .4byte 0xFFFFFDFF
_080F9E20: .4byte 0x0000021E
_080F9E24: .4byte 0x00000202
_080F9E28:
	adds r0, #1
	str r0, [r4]
_080F9E2C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
