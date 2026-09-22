	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _08018264
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	bl FUN_080026fc
_08018264:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x63
	bhi _08018272
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _0801827C
_08018272:
	adds r0, r4, #0
	movs r1, #2
	bl WeatherManager_SetState
	movs r0, #1
_0801827C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
