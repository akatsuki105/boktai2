	push {r4, lr}
	ldr r0, _0809C660 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0809C65A
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809C65A
	bl VM_GetValue
	ldr r2, _0809C664 @ =0x00003FA0
	adds r1, r4, r2
	strb r0, [r1]
_0809C65A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C660: .4byte 0x0300013C
_0809C664: .4byte 0x00003FA0
