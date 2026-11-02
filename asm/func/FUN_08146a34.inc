	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08146A4C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08146A50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08146A52
	.align 2, 0
_08146A4C: .4byte 0x0000046C
_08146A50:
	movs r0, #0
_08146A52:
	cmp r0, #0
	beq _08146A80
	ldr r4, _08146AB4 @ =FUN_08147030
	movs r3, #0x22
	ldr r2, _08146AB8 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08146ABC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08146A80:
	ldr r2, _08146ABC @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08146AC4
	movs r2, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08146AC0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08146AE2
	.align 2, 0
_08146AB4: .4byte FUN_08147030
_08146AB8: .4byte 0x0000046D
_08146ABC: .4byte 0x0000046B
_08146AC0: .4byte 0x00000484
_08146AC4:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08146AE2:
	pop {r4, r5}
	pop {r0}
	bx r0
