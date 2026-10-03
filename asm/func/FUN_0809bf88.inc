	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BFB0
	movs r4, #0
	ldr r0, _0809BFAC @ =0x00000F58
	adds r5, r6, r0
_0809BF9C:
	bl VM_GetValue
	adds r1, r5, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #9
	ble _0809BF9C
	b _0809BFC2
	.align 2, 0
_0809BFAC: .4byte 0x00000F58
_0809BFB0:
	movs r1, #1
	movs r4, #9
	ldr r2, _0809C008 @ =0x00000F61
	adds r0, r6, r2
_0809BFB8:
	strb r1, [r0]
	subs r0, #1
	subs r4, #1
	cmp r4, #0
	bge _0809BFB8
_0809BFC2:
	ldr r3, _0809C00C @ =0x00000F56
	adds r1, r6, r3
	ldrb r0, [r1]
	adds r3, #2
	adds r2, r6, r3
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C000
	movs r4, #0
	movs r7, #0
	adds r3, r2, #0
	movs r5, #0xff
_0809BFDC:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ands r0, r5
	cmp r0, #9
	bls _0809BFEA
	strb r7, [r1]
_0809BFEA:
	ldrb r0, [r1]
	adds r0, r3, r0
	ldrb r2, [r0]
	cmp r2, #0
	bne _0809C000
	adds r4, #1
	cmp r4, #9
	ble _0809BFDC
	ldr r1, _0809C00C @ =0x00000F56
	adds r0, r6, r1
	strb r2, [r0]
_0809C000:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809C008: .4byte 0x00000F61
_0809C00C: .4byte 0x00000F56
