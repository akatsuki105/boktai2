	push {r4, lr}
	ldr r0, _0809C534 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0809C52C
	ldr r1, _0809C538 @ =0x000009FC
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809C52C
	adds r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0809C52C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xe0
	movs r3, #0x90
	bl FUN_0808c95c
	ldr r1, _0809C53C @ =0x00000D99
	adds r0, r4, r1
	movs r1, #6
	strb r1, [r0]
	ldr r0, _0809C540 @ =0x00000382
	bl PlaySound_082406e0
_0809C52C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C534: .4byte 0x0300013C
_0809C538: .4byte 0x000009FC
_0809C53C: .4byte 0x00000D99
_0809C540: .4byte 0x00000382
