	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0809A198 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809A190
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808b6fc
	movs r0, #0x12
	bl FUN_08099b3c
	adds r0, r5, #0
	bl FUN_0808c700
	ldr r1, _0809A19C @ =FUN_0809a1a4
	adds r0, r5, #0
	movs r2, #1
	bl EntityCC28_SetState
	ldr r0, _0809A1A0 @ =0x00004018
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #4
	movs r2, #6
	movs r3, #0x16
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r1, [r5, #0x58]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0x10
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
_0809A190:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A198: .4byte 0x030044E0
_0809A19C: .4byte FUN_0809a1a4
_0809A1A0: .4byte 0x00004018
