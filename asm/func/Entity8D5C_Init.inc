	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08055874
	bl VM_GetPC
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x24]
	str r0, [r4, #0x2c]
	adds r0, r4, #0
	movs r1, #0
	bl Entity8D5C_MoveSelection
	ldr r0, _08055864 @ =0x000092B3
	ldr r1, _08055868 @ =0x0000519C
	bl GetFile
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0805586C @ =0x03004430
	ldr r2, _08055870 @ =0x04000008
	bl CpuSet
	movs r0, #0
	b _08055878
	.align 2, 0
_08055864: .4byte 0x000092B3
_08055868: .4byte 0x0000519C
_0805586C: .4byte 0x03004430
_08055870: .4byte 0x04000008
_08055874:
	movs r0, #1
	rsbs r0, r0, #0
_08055878:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
