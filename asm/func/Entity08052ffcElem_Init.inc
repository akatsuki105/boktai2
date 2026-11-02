	push {r4, r5, lr}
	sub sp, #4
	adds r2, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x14
	adds r2, #0x18
	adds r0, r5, #0
	adds r1, r2, #0
	movs r2, #3
	bl AuxSprite_Add
	movs r0, #0
	strb r0, [r5, #7]
	adds r4, #0x30
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08052EEC @ =0x05000002
	bl CpuSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052EEC: .4byte 0x05000002
