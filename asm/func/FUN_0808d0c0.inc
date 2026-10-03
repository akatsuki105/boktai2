	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, _0808D174 @ =0x0000C091
	ldr r1, _0808D178 @ =0x0000A413
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x18]
	ldr r1, _0808D17C @ =0x0000A7D7
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x1c]
	ldr r1, _0808D180 @ =0x0000A7E7
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x20]
	ldr r1, _0808D184 @ =0x0000A7F7
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x24]
	ldr r1, _0808D188 @ =0x000083C0
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x2c]
	ldr r1, _0808D18C @ =0x000009FE
	adds r0, r4, r1
	movs r6, #0
	strb r6, [r0]
	ldr r5, _0808D190 @ =0x000092B3
	ldr r1, _0808D194 @ =0x0000EFDA
	adds r0, r5, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x30]
	ldr r1, _0808D198 @ =0x0000ECBF
	adds r0, r5, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x34]
	ldr r1, _0808D19C @ =0x00005F5E
	adds r0, r5, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x38]
	ldr r1, _0808D1A0 @ =0x0000EAA8
	adds r0, r5, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0808a3c4
	ldr r1, _0808D1A4 @ =0x00000A94
	adds r0, r4, r1
	strb r6, [r0]
	subs r1, #0x6a
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_0808cf64
	adds r0, r4, #0
	bl FUN_0808d01c
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D174: .4byte 0x0000C091
_0808D178: .4byte 0x0000A413
_0808D17C: .4byte 0x0000A7D7
_0808D180: .4byte 0x0000A7E7
_0808D184: .4byte 0x0000A7F7
_0808D188: .4byte 0x000083C0
_0808D18C: .4byte 0x000009FE
_0808D190: .4byte 0x000092B3
_0808D194: .4byte 0x0000EFDA
_0808D198: .4byte 0x0000ECBF
_0808D19C: .4byte 0x00005F5E
_0808D1A0: .4byte 0x0000EAA8
_0808D1A4: .4byte 0x00000A94
