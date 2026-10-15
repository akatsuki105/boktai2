	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E2EA0
	bl FUN_0823d340
	ldr r2, _081E2ED4 @ =0x000015F0
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E2ED0
_081E2EA0:
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E2EB8
	bl FUN_0823d340
	ldr r2, _081E2ED8 @ =0x00001590
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E2ED0
_081E2EB8:
	movs r0, #0x59
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E2EE0
	bl FUN_0823d340
	ldr r2, _081E2EDC @ =0x000015F4
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _081E2EE0
_081E2ED0:
	movs r0, #0
	b _081E2EE2
	.align 2, 0
_081E2ED4: .4byte 0x000015F0
_081E2ED8: .4byte 0x00001590
_081E2EDC: .4byte 0x000015F4
_081E2EE0:
	movs r0, #1
_081E2EE2:
	pop {r4}
	pop {r1}
	bx r1
