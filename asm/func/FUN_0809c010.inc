	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x71
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809C02C
	bl VM_GetValue
	ldr r2, _0809C028 @ =0x00000F3D
	adds r1, r4, r2
	b _0809C032
	.align 2, 0
_0809C028: .4byte 0x00000F3D
_0809C02C:
	ldr r0, _0809C03C @ =0x00000F3D
	adds r1, r4, r0
	movs r0, #1
_0809C032:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C03C: .4byte 0x00000F3D
