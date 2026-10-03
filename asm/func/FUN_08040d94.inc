	push {r4, lr}
	adds r4, r0, #0
	movs r3, #0
	ldr r2, _08040DAC @ =0x085AB210
_08040D9C:
	ldrh r0, [r2]
	cmp r0, r4
	bne _08040DB0
	ldrb r0, [r2, #2]
	cmp r0, r1
	bne _08040DB0
	ldr r0, [r2, #4]
	b _08040DBA
	.align 2, 0
_08040DAC: .4byte 0x085AB210
_08040DB0:
	adds r2, #8
	adds r3, #1
	cmp r3, #0x14
	ble _08040D9C
	movs r0, #0
_08040DBA:
	pop {r4}
	pop {r1}
	bx r1
