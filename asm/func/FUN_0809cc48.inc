	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0
	bl SetBGPrioDirect
	ldr r0, _0809CCBC @ =0x000009FC
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0809CCC0 @ =0x03002C14
	ldrh r1, [r0]
	ldr r2, _0809CCC4 @ =0x00000F56
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0809CCC8 @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _0809CCCC @ =0x08DAA6D8
	movs r2, #0xff
	lsls r2, r2, #6
	adds r1, r4, r2
	bl FUN_08242a38
	adds r0, r4, #0
	bl FUN_0809bed8
	adds r0, r4, #0
	bl FUN_0809bf88
	adds r0, r4, #0
	bl FUN_0809c010
	adds r0, r4, #0
	bl FUN_0809bd14
	adds r0, r4, #0
	bl FUN_0808dddc
	adds r0, r4, #0
	bl FUN_0809b468
	movs r0, #0x64
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CCD4
	bl VM_GetValue
	ldr r2, _0809CCD0 @ =0x00004028
	adds r1, r4, r2
	str r0, [r1]
	b _0809CCDA
	.align 2, 0
_0809CCBC: .4byte 0x000009FC
_0809CCC0: .4byte 0x03002C14
_0809CCC4: .4byte 0x00000F56
_0809CCC8: .4byte 0x03002BE0
_0809CCCC: .4byte 0x08DAA6D8
_0809CCD0: .4byte 0x00004028
_0809CCD4:
	ldr r2, _0809CCF4 @ =0x00004028
	adds r0, r4, r2
	str r1, [r0]
_0809CCDA:
	movs r0, #0x56
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CCFC
	bl VM_GetValue
	ldr r2, _0809CCF8 @ =0x0000401F
	adds r1, r4, r2
	strb r0, [r1]
	b _0809CD02
	.align 2, 0
_0809CCF4: .4byte 0x00004028
_0809CCF8: .4byte 0x0000401F
_0809CCFC:
	ldr r2, _0809CD1C @ =0x0000401F
	adds r0, r4, r2
	strb r1, [r0]
_0809CD02:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CD24
	bl VM_GetValue
	ldr r2, _0809CD20 @ =0x00003FB4
	adds r1, r4, r2
	str r0, [r1]
	b _0809CD2A
	.align 2, 0
_0809CD1C: .4byte 0x0000401F
_0809CD20: .4byte 0x00003FB4
_0809CD24:
	ldr r2, _0809CD44 @ =0x00003FB4
	adds r0, r4, r2
	str r1, [r0]
_0809CD2A:
	movs r0, #0x44
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CD4C
	bl VM_GetValue
	ldr r2, _0809CD48 @ =0x00003FBC
	adds r1, r4, r2
	str r0, [r1]
	b _0809CD52
	.align 2, 0
_0809CD44: .4byte 0x00003FB4
_0809CD48: .4byte 0x00003FBC
_0809CD4C:
	ldr r2, _0809CD9C @ =0x00003FBC
	adds r0, r4, r2
	str r1, [r0]
_0809CD52:
	movs r0, #6
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	ldr r2, _0809CDA0 @ =0x00004014
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #4
	movs r1, #6
	movs r2, #0x16
	movs r3, #6
	bl TextPanel_Create
	ldr r2, _0809CDA4 @ =0x00004018
	adds r1, r4, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0808d0c0
	ldr r0, _0809CDA8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0809CDB0
	adds r0, r4, #0
	bl FUN_0808e224
	ldr r1, _0809CDAC @ =FUN_0808e400
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0809CDBE
	.align 2, 0
_0809CD9C: .4byte 0x00003FBC
_0809CDA0: .4byte 0x00004014
_0809CDA4: .4byte 0x00004018
_0809CDA8: .4byte 0x030047A4
_0809CDAC: .4byte FUN_0808e400
_0809CDB0:
	adds r0, r4, #0
	bl FUN_0808ce98
	ldr r1, _0809CDF0 @ =FUN_0808cf14
	adds r0, r4, #0
	bl FUN_0808a33c
_0809CDBE:
	adds r0, r4, #0
	bl FUN_0808cb00
	ldr r0, _0809CDF4 @ =0x00000A99
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _0809CDF8 @ =0x00000A9A
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _0809CDFC @ =0x00000A9B
	adds r1, r4, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	subs r2, #0x9b
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0809CE00 @ =0x0300013C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809CDF0: .4byte FUN_0808cf14
_0809CDF4: .4byte 0x00000A99
_0809CDF8: .4byte 0x00000A9A
_0809CDFC: .4byte 0x00000A9B
_0809CE00: .4byte 0x0300013C
