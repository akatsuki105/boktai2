	push {r4, lr}
	ldr r4, _0809C33C @ =0x0300013C
	ldr r0, [r4]
	cmp r0, #0
	beq _0809C334
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809C334
	bl VM_GetValue
	ldr r1, [r4]
	ldr r2, _0809C340 @ =0x00000F3D
	adds r1, r1, r2
	strb r0, [r1]
_0809C334:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C33C: .4byte 0x0300013C
_0809C340: .4byte 0x00000F3D
