	push {r4, lr}
	ldr r4, _080A11FC @ =0x03000148
	ldr r1, [r4]
	cmp r1, #0
	beq _080A123A
	movs r0, #1
	strh r0, [r1, #0x1a]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1200
	bl VM_GetValue
	ldr r1, [r4]
	strh r0, [r1, #0x1c]
	bl VM_GetValue
	ldr r1, [r4]
	b _080A1206
	.align 2, 0
_080A11FC: .4byte 0x03000148
_080A1200:
	ldr r1, [r4]
	movs r0, #3
	strh r0, [r1, #0x1c]
_080A1206:
	strh r0, [r1, #0x1e]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1228
	bl VM_GetValue
	ldr r4, _080A1224 @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x20]
	bl VM_GetValue
	ldr r1, [r4]
	b _080A1230
	.align 2, 0
_080A1224: .4byte 0x03000148
_080A1228:
	ldr r0, _080A1240 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0x78
	strh r0, [r1, #0x20]
_080A1230:
	strh r0, [r1, #0x22]
	ldr r0, _080A1240 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080A123A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1240: .4byte 0x03000148
