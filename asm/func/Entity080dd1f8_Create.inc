	push {r4, lr}
	ldr r0, _080DD22C @ =0x0300016C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD23E
	ldr r1, _080DD230 @ =0x00000F6C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DD23C
	ldr r1, _080DD234 @ =Entity080dd1f8_Update
	ldr r2, _080DD238 @ =0x080DD15D
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080dd1f8_Init
	cmp r0, #0
	bge _080DD23C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DD23E
	.align 2, 0
_080DD22C: .4byte 0x0300016C
_080DD230: .4byte 0x00000F6C
_080DD234: .4byte Entity080dd1f8_Update
_080DD238: .4byte 0x080DD15D
_080DD23C:
	adds r0, r4, #0
_080DD23E:
	pop {r4}
	pop {r1}
	bx r1
