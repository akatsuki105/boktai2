	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808CF0E
	ldr r0, _0808CEF0 @ =0x000009FE
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #7
	beq _0808CF0E
	cmp r0, #2
	bhi _0808CF0E
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	adds r0, r4, #0
	movs r1, #0
	movs r2, #9
	movs r3, #0x12
	bl FUN_0808a9a4
	adds r0, r4, #0
	bl FUN_0808afac
	ldrb r0, [r5]
	cmp r0, #0
	bne _0808CEF4
	adds r0, r4, #0
	bl FUN_0808ad5c
	b _0808CEFC
	.align 2, 0
_0808CEF0: .4byte 0x000009FE
_0808CEF4:
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_0808abec
_0808CEFC:
	adds r0, r4, #0
	bl FUN_0808cc14
	adds r0, r4, #0
	bl FUN_0808cc84
	adds r0, r4, #0
	bl FUN_0808b1bc
_0808CF0E:
	pop {r4, r5}
	pop {r0}
	bx r0
