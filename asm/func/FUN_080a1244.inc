	push {r4, lr}
	ldr r4, _080A1268 @ =0x03000148
	ldr r1, [r4]
	cmp r1, #0
	beq _080A12CE
	movs r0, #2
	strh r0, [r1, #0x1a]
	movs r0, #0x64
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A126C
	bl VM_GetValue
	ldr r1, [r4]
	strh r0, [r1, #0x2a]
	b _080A1270
	.align 2, 0
_080A1268: .4byte 0x03000148
_080A126C:
	ldr r0, [r4]
	strh r1, [r0, #0x2a]
_080A1270:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1290
	bl VM_GetValue
	ldr r4, _080A128C @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x1c]
	bl VM_GetValue
	ldr r1, [r4]
	b _080A1298
	.align 2, 0
_080A128C: .4byte 0x03000148
_080A1290:
	ldr r0, _080A12B8 @ =0x03000148
	ldr r1, [r0]
	movs r0, #3
	strh r0, [r1, #0x1c]
_080A1298:
	strh r0, [r1, #0x1e]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A12BC
	bl VM_GetValue
	ldr r4, _080A12B8 @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x20]
	bl VM_GetValue
	ldr r1, [r4]
	b _080A12C4
	.align 2, 0
_080A12B8: .4byte 0x03000148
_080A12BC:
	ldr r0, _080A12D4 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0x78
	strh r0, [r1, #0x20]
_080A12C4:
	strh r0, [r1, #0x22]
	ldr r0, _080A12D4 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080A12CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A12D4: .4byte 0x03000148
