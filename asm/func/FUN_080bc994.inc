	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BC9AA
	bl VM_GetValue
	adds r5, r0, #0
	b _080BC9AC
_080BC9AA:
	movs r5, #0
_080BC9AC:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BC9F8
	movs r4, #0
	cmp r4, r5
	bge _080BC9CE
	ldr r0, _080BCA14 @ =0x00001304
	adds r6, r7, r0
_080BC9C0:
	bl VM_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, r5
	blt _080BC9C0
_080BC9CE:
	cmp r4, #0xb
	bgt _080BC9E6
	ldr r0, _080BCA14 @ =0x00001304
	adds r2, r7, r0
	movs r3, #0xff
_080BC9D8:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BC9D8
_080BC9E6:
	ldr r2, _080BCA18 @ =0x0000130C
	adds r1, r7, r2
	movs r4, #3
_080BC9EC:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BC9EC
_080BC9F8:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BCA0C
	bl FUN_0823d340
	ldr r2, _080BCA1C @ =0x000012E8
	adds r1, r7, r2
	str r0, [r1]
_080BCA0C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BCA14: .4byte 0x00001304
_080BCA18: .4byte 0x0000130C
_080BCA1C: .4byte 0x000012E8
