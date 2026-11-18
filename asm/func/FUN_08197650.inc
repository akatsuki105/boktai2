	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197676
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197678
_08197676:
	movs r0, #0
_08197678:
	cmp r0, #0
	beq _08197696
	ldr r0, _081976B4 @ =0x00000C64
	adds r1, r4, r0
	movs r0, #0x64
	str r0, [r1]
	ldr r0, _081976B8 @ =0x00000C44
	adds r1, r4, r0
	ldr r0, _081976BC @ =FUN_081963f0
	str r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _081976C0 @ =FUN_08195c94
	str r0, [r1]
_08197696:
	adds r0, r4, #0
	bl FUN_08196378
	ldr r1, _081976B8 @ =0x00000C44
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081976AC
	adds r0, r4, #0
	bl _call_via_r1
_081976AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081976B4: .4byte 0x00000C64
_081976B8: .4byte 0x00000C44
_081976BC: .4byte FUN_081963f0
_081976C0: .4byte FUN_08195c94
