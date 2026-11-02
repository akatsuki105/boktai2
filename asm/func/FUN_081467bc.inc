	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r0, _081467D4 @ =0x0000046C
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081467D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081467DA
	.align 2, 0
_081467D4: .4byte 0x0000046C
_081467D8:
	movs r0, #0
_081467DA:
	cmp r0, #0
	beq _08146886
	ldr r0, _0814689C @ =0x00000482
	adds r1, r3, r0
	movs r6, #0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _081468A0 @ =0x00000222
	adds r0, r3, r1
	strh r5, [r0]
	adds r1, #0x2c
	adds r0, r3, r1
	strh r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r3, r0
	ldr r0, _081468A4 @ =0xFFFFFC7F
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r3, r1
	ldr r1, _081468A8 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08146846
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _081468AC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _081468B0 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r6, [r0]
	adds r1, #2
	adds r0, r3, r1
	strh r5, [r0]
	subs r1, #0x1c
	adds r0, r3, r1
	strh r5, [r0]
_08146846:
	ldr r0, _081468B4 @ =0xFFFFFBFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r0, _081468B8 @ =0x00000542
	adds r1, r3, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	str r5, [r0]
	ldr r1, _081468BC @ =0x000005A4
	adds r0, r3, r1
	ldr r2, [r0]
	ldr r0, _081468C0 @ =0x0000046D
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081468C4 @ =0x0000046B
	adds r0, r3, r1
	strb r6, [r0]
	adds r1, #0xe8
	adds r0, r3, r1
	strb r6, [r0]
	adds r1, #0x25
	adds r0, r3, r1
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r3, r1
	strh r5, [r0]
_08146886:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814689C: .4byte 0x00000482
_081468A0: .4byte 0x00000222
_081468A4: .4byte 0xFFFFFC7F
_081468A8: .4byte 0xF3FFFFFF
_081468AC: .4byte 0xFEFFFFFF
_081468B0: .4byte 0xFFFFFDFF
_081468B4: .4byte 0xFFFFFBFF
_081468B8: .4byte 0x00000542
_081468BC: .4byte 0x000005A4
_081468C0: .4byte 0x0000046D
_081468C4: .4byte 0x0000046B
