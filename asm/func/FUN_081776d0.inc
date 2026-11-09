	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #1
	ldr r2, _081776EC @ =0x00001008
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081776F0
	movs r0, #1
	b _081776F2
	.align 2, 0
_081776EC: .4byte 0x00001008
_081776F0:
	movs r0, #0
_081776F2:
	cmp r0, #0
	beq _08177714
	ldr r0, _0817771C @ =0x00001008
	adds r2, r4, r0
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08177720 @ =0x00000FC4
	adds r4, r4, r1
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl Mover_Unlink
_08177714:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817771C: .4byte 0x00001008
_08177720: .4byte 0x00000FC4
